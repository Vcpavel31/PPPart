#include "pppart.h"
#include "ui_pppart.h"

PPPart::PPPart(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PPPart)
{
    // Set up UI
    ui->setupUi(this);

    // Hide vertical header for Information table and set column width for parts table
    ui->Information->verticalHeader()->hide();
    ui->parts->setColumnWidth(0, 0);

    // Get all data
    getAllData();

    // Get category data from networkSQL
    QMap<QString, QStringList> data = network.getData("MACRO(CategoryList)");

    // Hide second column of categories table and clear it
    ui->categories->setColumnHidden(1, true);
    ui->categories->clear();

    // Iterate over category data and insert items into categories table
    for (int i = 0; i < data["ID"].size(); i++) {
        QString categoryName = data["Name"][i];
        QString categoryId = data["ID"][i];
        QString ordered = data["Ordered"][i];

        // Check if category is ordered
        if (ordered.isEmpty()) {
            // Insert top-level item for unordered category
            ui->categories->addTopLevelItem(new QTreeWidgetItem({categoryName, categoryId}));
        } else {
            // Find parent item for ordered category
            QList<QTreeWidgetItem*> parentItems = ui->categories->findItems(ordered, Qt::MatchExactly|Qt::MatchRecursive, 1);
            if (!parentItems.isEmpty()) {
                // Add child item to parent item
                QTreeWidgetItem* parentItem = parentItems.first();
                parentItem->addChild(new QTreeWidgetItem({categoryName, categoryId}));
            }
        }
    }

}

PPPart::~PPPart()
{
    delete ui;
}

void PPPart::getAllData()
{
}

void PPPart::on_categories_itemClicked(QTreeWidgetItem *item, int column) {
    (void) column;
    ui->parts->clear();
    ui->parts->setUpdatesEnabled(false);

    QMap<QString, QStringList> attributes = network.getData("MACRO(Attributes(" + item->text(1) + "))");

    QStringList labels = {"ID", "Množství"};
    for (int h = 0; h != attributes["ID"].size(); ++h) {
        labels << attributes["Attribute_Name"][h];
    }

    ui->parts->setColumnCount(labels.size());
    ui->parts->setHeaderLabels(labels);

    const auto items = network.getData("MACRO(Items_in_Category(" + item->text(1) + "(" + item->text(1) + ")))");
    const auto ID_Items = items["ID"];

    for (int i = 0; i != ID_Items.size(); ++i) {
        QMap<QString, QStringList> data;
        QString Query = ("SELECT `ID`,`Name` AS 'Název', `EAN`, `Product_number` FROM `Items` WHERE `ID` = " + ID_Items[i]);
        QMap<QString, QStringList> response = network.getData(Query);
        QMapIterator<QString, QStringList> why(response);
        while (why.hasNext()) {
            why.next();
            data[why.key()] = why.value();
        }

        response = network.getData("MACRO(Attribute(" + ID_Items[i] + "))");

        for (int j = 0; j != response["Attribute_Name"].count(); ++j) {
            data[response["Attribute_Name"][j]] << response["Attribute_Value"][j];
        }

        response = network.getData("MACRO(Item_Amount(" + ID_Items[i] + "))");

        data["Množství"] << response["Amount"];

        QStringList hodnoty(labels.count());
        for (int k = 0; k != labels.count(); ++k) {
            if (data[labels[k]].isEmpty()) {
                hodnoty[k] = "";
            } else {
                data[labels[k]].removeAll(QString(""));
                hodnoty[k] = data[labels[k]].join(" ");
            }
        }

        ui->parts->addTopLevelItem(new QTreeWidgetItem(hodnoty));
    }

    ui->parts->setUpdatesEnabled(true);
    ui->parts->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    int nameColumn = -1, idColumn = -1;
    QTreeWidgetItem *header = ui->parts->headerItem();
    for (int i = 0; i < header->columnCount(); ++i) {
        if (header->text(i) == "Název") {
            nameColumn = i;
        } else if (header->text(i) == "ID") {
            idColumn = i;
        }
    }

    ui->parts->setColumnHidden(idColumn, true);
    ui->parts->sortByColumn(nameColumn, Qt::AscendingOrder);

}


void PPPart::on_settings_pressed() {

}


void PPPart::on_parts_itemDoubleClicked(QTreeWidgetItem* item, int column) {
    (void) column; // dont care

    if (item->childCount()) {
        return;
    }

    static const QString MNOZSTVI_TEXT = QStringLiteral("Množství");
    int mnozstvi = -1;
    QTreeWidgetItem* header = ui->parts->headerItem();
    for (int i = 0; i < header->columnCount(); ++i) {
        if (header->text(i) == MNOZSTVI_TEXT) {
            mnozstvi = i;
            break;
        }
    }
    if (mnozstvi == -1) {
        qWarning() << "Sloupec s množstvím nenalezen!";
        return;
    }

    const int itemMnozstvi = item->text(mnozstvi).toInt();
    bool ok;
    const QString text = QInputDialog::getText(this, tr("Počet kusů"), item->text(mnozstvi), QLineEdit::Normal, "1", &ok);
    if (!ok || text.isEmpty()) {
        return;
    }
    const int enteredMnozstvi = text.toInt();
    if (enteredMnozstvi > itemMnozstvi) {
        QMessageBox::warning(this, tr("Nedostatečné množství na skladu."), tr("Nedostatečné množství na skladu. Opakujte akci."));
        return;
    }

    ////// Přidání do výdeje
}



void PPPart::on_income_pressed()
{
    income.show();
}

int PPPart::getIDColumnIndex() const {
    static int idColumnIndex = -1; // use static to cache the value across function calls
    if (idColumnIndex == -1) {
        QTreeWidgetItem *header = ui->parts->headerItem();
        for (int i = 0; i < header->columnCount(); i++) {
            if(header->text(i) == "ID"){
                idColumnIndex = i;
                break;
            }
        }
    }
    return idColumnIndex;
}

void PPPart::createGraph(QTreeWidgetItem* item, int idColumnIndex) {
    QMap<QString, QStringList> response = network.getData("MACRO(Amount_Count("+item->text(idColumnIndex)+"))");
    if(response["COUNT(`ID`)"][0].toInt() == 0) return;

    QLineSeries *series = new QLineSeries();
    response = network.getData("MACRO(All_Amounts("+item->text(idColumnIndex)+"))");
    for(int j = 0; j < response["Amount"].count(); j++){
        QStringList dateParts = response["Date"][j].split(" ")[0].split("-");
        QDate date = QDate(dateParts[0].toInt(), dateParts[1].toInt(), dateParts[2].toInt());
        QTime time(0, 0, 0);
        QDateTime momentInTime(date, time);
        series->append(momentInTime.toMSecsSinceEpoch(), response["Amount"][j].toInt());
    }

    QDateTimeAxis *axisX = new QDateTimeAxis();
    axisX->setTickCount(10);
    axisX->setFormat("dd.MM.yyyy");
    axisX->setTitleText("Datum");

    response = network.getData("MACRO(Amount_Range("+item->text(idColumnIndex)+"))");
    QString minDateStr = response["Min_Date"][0];
    QString maxDateStr = response["Max_Date"][0];

    const QDate minDate = QDate::fromString(minDateStr, "yyyy-MM-dd");
    const QTime minTime = QTime::fromString(minDateStr.split(" ")[1], "hh:mm:ss");
    const QDate maxDate = QDate::fromString(maxDateStr, "yyyy-MM-dd");
    const QTime maxTime = QTime::fromString(maxDateStr.split(" ")[1], "hh:mm:ss");

    axisX->setMin(QDateTime(minDate, minTime));
    axisX->setMax(QDateTime(maxDate, maxTime));

    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Množství");
    axisY->setMin(response["Min_Amount"][0].toInt());
    axisY->setMax(response["Max_Amount"][0].toInt());

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Množství položek ve skladu");
    chart->addAxis(axisY, Qt::AlignLeft);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisY);
    series->attachAxis(axisX);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->stock_info);
    if(ui->graph->itemAt(0)!=NULL)
        ui->graph->removeItem(ui->graph->itemAt(0));
    ui->graph->addWidget(chartView);
}


void PPPart::on_parts_itemClicked(QTreeWidgetItem *item, int column)
{
    int idColumnIndex = getIDColumnIndex();

    if (idColumnIndex < 0) {
        qDebug() << "ID column not found";
        return;
    }

    QMap<QString, QStringList> response = network.getData("MACRO(Item_Info("+item->text(idColumnIndex)+"))");

    int k = 0;
    for (auto i = response.begin(); i != response.end(); ++i) {
        const QString& key = i.key();
        if (key == "Debug" || key == "Pass" || key == "Query" || key == "User") {
            continue;
        }

        QStringList& value = i.value();
        if (k >= ui->Information->rowCount())
            ui->Information->insertRow(k);

        QLabel *nazev = nullptr;
        QLabel *hodnota = nullptr;

        if (k < ui->Information->rowCount()) {
            // reuse existing widgets
            nazev = qobject_cast<QLabel*>(ui->Information->cellWidget(k, 0));
            hodnota = qobject_cast<QLabel*>(ui->Information->cellWidget(k, 1));
        }

        if (!nazev) {
            nazev = new QLabel(ui->Information);
            ui->Information->setCellWidget(k, 0, nazev);
        }

        if (!hodnota) {
            hodnota = new QLabel(ui->Information);
            ui->Information->setCellWidget(k, 1, hodnota);
        }

        nazev->setText(key);
        hodnota->setText(value.empty() ? "" : value.front());

        ++k;
    }

    while (k < ui->Information->rowCount()) {
        ui->Information->removeRow(k);
    }

    response = network.getData("MACRO(Item_Attributes("+item->text(idColumnIndex)+"))");

    bool information = false;
    bool dates = false;

    auto name = response["Name"];
    auto value = response["Value"];
    auto info = response["Info"];
    auto date = response["Date"];

    ui->Information->setUpdatesEnabled(false);
    ui->Information->setRowCount(name.count());
    ui->Information->verticalHeader()->setVisible(false);
    ui->Information->setSortingEnabled(false);
    ui->Information->horizontalHeader()->setStretchLastSection(true);

    for(int j = 0; j != name.count(); j++) {
        QLabel *nazev = new QLabel;
        nazev->setText(name[j]);
        ui->Information->setCellWidget(k, 0, nazev);

        if(!value[j].isEmpty()) {
            QLabel *hodnota = new QLabel;
            hodnota->setText(value[j]);
            ui->Information->setCellWidget(k, 1, hodnota);
        }
        if(!info[j].isEmpty()) {
            information = true;
            QLabel *info_label = new QLabel;
            info_label->setText(info[j]);
            ui->Information->setCellWidget(k, 2, info_label);
        }
        if(!date.isEmpty()) {
            dates = true;
            QLabel *datum = new QLabel;
            datum->setText(date[j]);
            ui->Information->setCellWidget(k, 3, datum);
        }
        ++k;
    }

    ui->Information->setColumnHidden(2, !information);
    ui->Information->setColumnHidden(3, !dates);
    ui->Information->setUpdatesEnabled(true);

    createGraph(item, idColumnIndex);

    (void) column; // dont care
}
