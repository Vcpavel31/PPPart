#include "pppart.h"
#include "ui_pppart.h"

PPPart::PPPart(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PPPart)
{
    ui->setupUi(this);
    //settings->setDefaultFormat(QSettings::IniFormat);
    //qDebug() << settings->status() << " " << settings->fileName();

    ui->Information->verticalHeader()->hide();
    ui->parts->setColumnWidth(0,0);

    getAllData();

    QMap<QString, QStringList> data = network.getData("MACRO(CategoryList)");
    ui->categories->setColumnHidden(1, 1);
    ui->categories->clear();
    for(int i = 0; i != data["ID"].size(); i++){
        if(data["Ordered"][i].isEmpty()){
            ui->categories->insertTopLevelItem(ui->categories->topLevelItemCount(), new QTreeWidgetItem(QStringList({data["Name"][i], data["ID"][i]})));
        }
        else{
            QList<QTreeWidgetItem *> items = ui->categories->findItems(data["Ordered"][i], Qt::MatchExactly|Qt::MatchRecursive, 1);
            if(!items.isEmpty()){ // parent item exists
                //only one item with same ID => at(0)
                items.at(0)->addChild(new QTreeWidgetItem(QStringList({data["Name"][i], data["ID"][i]})));
                qDebug() << "Parent item exists: " << items.at(0)->text(0);
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

void PPPart::on_categories_itemClicked(QTreeWidgetItem *item, int column)
{

    ui->parts->clear();
    qDebug() << "left bar" << item->text(1);

    ui->parts->setColumnCount(0);

    QMap<QString, QStringList> attributes = network.getData("MACRO(Attributes("+item->text(1)+"))");
    qDebug() << "Attributes: " << attributes;

    QStringList labels = {"ID", "Množství"};

    for(int h = 0; h!= attributes["ID"].size(); h++){
        //qDebug() << attributes["Attribute_Name"][h];
        //ui->parts->setColumnCount(ui->parts->columnCount()+1);
        labels << attributes["Attribute_Name"][h];
    }
    //labels.sort(Qt::CaseSensitive);
    ui->parts->setColumnCount(labels.count());
    ui->parts->setHeaderLabels(labels);
    /////////////////////////////////////////////////////////////////////////////////
    /// \brief Data součástek
    /// Získání informací o jednotlivých položkách ve skladu odpovídajícím kategorii

    QString Query = ("  SELECT `Categories_Items`.`Item_ID` AS 'ID'\
                FROM `Categories_Items`, `Categories_Arrangement`\
                WHERE `Categories_Items`.`Category_ID` = `Categories_Arrangement`.`Category` AND (\
                (`Categories_Arrangement`.`Ordered` = "+item->text(1)+") OR\
                (`Categories_Arrangement`.`Category` = "+item->text(1)+")\
            )");
    QMap<QString, QStringList> items = network.getData(Query);
    qDebug() << "AHA" << items;
    for(int i = 0; i != items["ID"].size(); i++){
        hodnoty = {};
        QMap<QString, QStringList> data;
        qDebug() << items["ID"][i];
        Query = ("SELECT `ID`,`Name` AS 'Název', `EAN`, `Product_number` FROM `Items` WHERE `ID` = "+items["ID"][i]);
        QMap<QString, QStringList> response = network.getData(Query);
        qDebug() << "RESPONSE Default" << response;
        QMapIterator<QString, QStringList> why(response);
        while (why.hasNext()) {
            why.next();
            data[why.key()] = why.value();
        }

        response = network.getData("MACRO(Attribute("+items["ID"][i]+"))");
        //qDebug() << "RESPONSE Attributes" << response;
        for(int j = 0; j != response["Attribute_Name"].count(); j++)
            data[response["Attribute_Name"][j]] << response["Attribute_Value"][j];

        /////////////////////////////////////////////////////////////////////// Zíksat Množství a zapsat ho

        response = network.getData("MACRO(Item_Amount("+items["ID"][i]+"))");
        //qDebug() << "RESPONSE Amount" << response;
        data["Množství"] << response["Amount"];

        for(int k = 0; k != labels.count(); k++){
            if(data[labels[k]].isEmpty()){
                //qDebug() << labels[k] << data[labels[k]];
                hodnoty += "";
            }
            else{
                //qDebug() << labels[k] << data[labels[k]];

                data[labels[k]].removeAll(QString(""));

                hodnoty += data[labels[k]];
            }
        }
        //qDebug() << hodnoty;

        ui->parts->insertTopLevelItem(ui->parts->topLevelItemCount(), new QTreeWidgetItem(hodnoty));
    }

    ui->parts->update();

    (void) item; // dont care
    (void) column; // dont care

    int nazev, id = 0;
    QTreeWidgetItem *header = ui->parts->headerItem();
    for (int i = 0; i < header->columnCount(); i++) {

        // Set column width to fit content in every column
        ui->parts->resizeColumnToContents(i);

        if(header->text(i) == "Název"){
            qDebug() << "Sloupec Název: " << i;
            nazev = i;
        }
        if(header->text(i) == "ID"){
            qDebug() << "Sloupec ID: " << i;
            id = i;
        }
    }
    ui->parts->setColumnHidden(id, 1);
    ui->parts->sortItems(nazev, Qt::AscendingOrder);
    ui->parts->sortColumn();
}


void PPPart::on_settings_pressed()
{
    // ?????????????????????????????????????????????????????????????
    // network.getData("SELECT `Interni_ID`, `EAN` FROM `EAN` WHERE `EAN` LIKE '%12%'");
}

void PPPart::on_parts_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    (void) column; // dont care about column probably
    bool ok;
    int mnozstvi = 0;
    QTreeWidgetItem *header = ui->parts->headerItem();
    for (int i = 0; i < header->columnCount(); i++) {
        if(header->text(i) == "Množství"){
            qDebug() << "Sloupec Množství: " << i;
            mnozstvi = i;
        }
    }
    //qDebug() << "Množství" << ;//ui->parts->find("Množství", Qt::MatchContains|Qt::MatchRecursive, 0);
    if(!item->childCount()) //if havent any children
        {
            QString text = QInputDialog::getText(this, tr("Počet kusů"), item->text(mnozstvi), QLineEdit::Normal, "1",  &ok);
            if (ok && !text.isEmpty()) // ok pressed?
                {
                    if(item->text(1).toInt() >= text.toInt()) //enought parts?
                        {
                            qDebug() << "Noice";
                    } else
                        {
                            QMessageBox msgBox;
                            msgBox.setText(tr("Nedostatečné množství na skladu. Opakujte akci."));
                            msgBox.exec();
                    }
            }
    }
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
