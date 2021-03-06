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

    QString Query = "SELECT `Categories`.ID AS 'ID',\
                     `Categories`.`Name` AS 'Name',\
                     `Categories_Arrangement`.`Ordered` AS 'Ordered'\
                     FROM `Categories`, `Categories_Arrangement`\
                     WHERE `Categories`.ID = `Categories_Arrangement`.`Category` AND `Categories`.`Hidden` = '0'";
    QMap<QString, QStringList> data = network.getData(Query);
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

    QString Query = ("  SELECT  `Attributes`.*\
                        FROM    `Attributes`, `Categories_Attributes`, `Categories_Arrangement`\
                        WHERE   `Attributes`.`ID` = `Categories_Attributes`.`Attributes` AND\
                                `Categories_Attributes`.`Hidden` = 0 AND\
                                `Categories_Attributes`.`Category` = `Categories_Arrangement`.`Category` AND (\
                                    (`Categories_Arrangement`.`Category` = "+item->text(1)+")\
                                )\
                        ORDER BY `Attributes`.`ID` ASC");
//                                    (`Categories_Arrangement`.`Ordered` = "+item->text(1)+") OR

    qDebug() << Query;
    QMap<QString, QStringList> attributes = network.getData(Query);
    //qDebug() << attributes;

    QStringList labels = {"ID", "Mno??stv??"};

    for(int h = 0; h!= attributes["ID"].size(); h++){
        //qDebug() << attributes["Attribute_Name"][h];
        //ui->parts->setColumnCount(ui->parts->columnCount()+1);
        labels << attributes["Attribute_Name"][h];
    }
    //labels.sort(Qt::CaseSensitive);
    ui->parts->setColumnCount(labels.count());
    ui->parts->setHeaderLabels(labels);
    /////////////////////////////////////////////////////////////////////////////////
    /// \brief Data sou????stek
    /// Z??sk??n?? informac?? o jednotliv??ch polo??k??ch ve skladu odpov??daj??c??m kategorii

    Query = ("  SELECT `Categories_Items`.`Item_ID` AS 'ID'\
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
        Query = ("SELECT `ID`,`Name` AS 'N??zev', `EAN`, `Product_number` FROM `Items` WHERE `ID` = "+items["ID"][i]);
        QMap<QString, QStringList> response = network.getData(Query);
        qDebug() << "RESPONSE Default" << response;
        QMapIterator<QString, QStringList> why(response);
        while (why.hasNext()) {
            why.next();
            data[why.key()] = why.value();
        }

        Query = "SELECT `Attribute`.`Attribute_Info`,`Attribute`.`Attribute_Date`,`Attribute`.`Attribute_Value` AS 'Attribute_Value', `Attributes`.`Attribute_Name` AS 'Attribute_Name' FROM `Attribute`,`Attributes` WHERE `Attribute`.`Item_ID` = "+items["ID"][i]+" AND `Attributes`.`ID` = `Attribute`.`Attribute_Option`";
        response = network.getData(Query);
        qDebug() << "RESPONSE Attributes" << response;
        for(int j = 0; j != response["Attribute_Name"].count(); j++){
            qDebug() << j;
            qDebug() << response["Attribute_Name"][j];
            qDebug() << response["Attribute_Value"][j];
            data[response["Attribute_Name"][j]] << response["Attribute_Value"][j];
        }

        /////////////////////////////////////////////////////////////////////// Z??ksat Mno??stv?? a zapsat ho

        Query = ("SELECT `Amount`,`Date` FROM `Amounts` WHERE `Item_ID` = '"+items["ID"][i]+"' ORDER BY `Amounts`.`Date` DESC LIMIT 1");
        response = network.getData(Query);
        qDebug() << "RESPONSE Amount" << response;
        data["Mno??stv??"] << response["Amount"];

        for(int k = 0; k != labels.count(); k++){
            if(data[labels[k]].isEmpty()){
                qDebug() << labels[k] << data[labels[k]];
                hodnoty += "";
            }
            else{
                qDebug() << labels[k] << data[labels[k]];

                data[labels[k]].removeAll(QString(""));

                hodnoty += data[labels[k]];
            }
        }
        qDebug() << hodnoty;

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

        if(header->text(i) == "N??zev"){
            qDebug() << "Sloupec N??zev: " << i;
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
        if(header->text(i) == "Mno??stv??"){
            qDebug() << "Sloupec Mno??stv??: " << i;
            mnozstvi = i;
        }
    }
    //qDebug() << "Mno??stv??" << ;//ui->parts->find("Mno??stv??", Qt::MatchContains|Qt::MatchRecursive, 0);
    if(!item->childCount()) //if havent any children
        {
            QString text = QInputDialog::getText(this, tr("Po??et kus??"), item->text(mnozstvi), QLineEdit::Normal, "1",  &ok);
            if (ok && !text.isEmpty()) // ok pressed?
                {
                    if(item->text(1).toInt() >= text.toInt()) //enought parts?
                        {
                            qDebug() << "Noice";
                    } else
                        {
                            QMessageBox msgBox;
                            msgBox.setText(tr("Nedostate??n?? mno??stv?? na skladu. Opakujte akci."));
                            msgBox.exec();
                    }
            }
    }
}


void PPPart::on_income_pressed()
{
    income.show();
}

void PPPart::on_parts_itemClicked(QTreeWidgetItem *item, int column)
{

    int id = 0;
    QTreeWidgetItem *header = ui->parts->headerItem();
    for (int i = 0; i < header->columnCount(); i++) {
        if(header->text(i) == "ID"){
            qDebug() << "Sloupec ID: " << i;
            id = i;
        }
    }


    qDebug() << item->text(id);


    ui->Information->setRowCount(100);

    QString Query = "SELECT `ID`,`Name` AS 'N??zev', `EAN`, `Product_number` AS '????slo v??robku' FROM `Items` WHERE `ID` = "+item->text(id);
    QMap<QString, QStringList> response = network.getData(Query);
    QMapIterator<QString, QStringList> primary(response);
    int i = 0;
    while (primary.hasNext()) {
        primary.next();
        qDebug() << primary.key() << primary.value()[0];
        QLabel *nazev = new QLabel(primary.key());
        ui->Information->setCellWidget(i, 0, nazev);
        QLabel *hodnota = new QLabel(primary.value()[0]);
        ui->Information->setCellWidget(i, 1, hodnota);
        i++;
    }

    Query = "SELECT `Attributes`.`Attribute_Name` AS 'Name', `Attribute`.`Attribute_Value` AS 'Value', `Attribute`.`Attribute_Info` AS 'Info', `Attribute`.`Attribute_Date` AS 'Date' FROM `Attribute`, `Attributes` WHERE `Attributes`.`ID` = `Attribute`.`Attribute_Option` AND `Item_ID` ="+item->text(id);
    response = network.getData(Query);

    bool inforamtion = false;
    bool dates = false;

    for(int j = 0; j != response["Name"].count(); j++){
        qDebug() << j;

        qDebug() << response["Name"][j];
        QLabel *nazev       = new QLabel(response["Name"][j]);
        ui->Information->setCellWidget(i, 0, nazev);

        if(response["Value"][j] != ""){
            qDebug() << response["Value"][j];
            QLabel *hodnota     = new QLabel(response["Value"][j]);
            ui->Information->setCellWidget(i, 1, hodnota);
        }
        if(response["Info"][j] != ""){
            inforamtion = true;
            qDebug() << response["Info"][j];
            QLabel *info        = new QLabel(response["Info"][j]);
            ui->Information->setCellWidget(i, 2, info);
        }
        if(response["Date"][j] != ""){
            dates = true;
            qDebug() << response["Date"][j];
            QLabel *datum       = new QLabel(response["Date"][j]);
            ui->Information->setCellWidget(i, 3, datum);
        }

        i++;
    }

    if(inforamtion == false) ui->Information->setColumnWidth(2,0);
    else ui->Information->resizeColumnToContents(2);
    if(dates == false) ui->Information->setColumnWidth(3,0);
    else ui->Information->resizeColumnToContents(3);

    ui->Information->setRowCount(i);

    Query = "SELECT COUNT(`ID`) FROM `Amounts` WHERE `Item_ID` = "+item->text(id);
    response = network.getData(Query);
    if(response["COUNT(`ID`)"][0].toInt() != 0){
        qDebug() << "Prepare for graph";

        QLineSeries *series = new QLineSeries();


        /////////////////////////////////////////////////////////////////////// Z??ksat Mno??stv??

        Query = ("SELECT `Amount`,`Date` FROM `Amounts` WHERE `Item_ID` = '"+item->text(id)+"' ORDER BY `Amounts`.`Date` DESC");
        response = network.getData(Query);
        //qDebug() << "RESPONSE Amount" << response;

        for(int j = 0; j != response["Amount"].count(); j++){
            /*qDebug() << j << QDate(response["Date"][j].split(" ")[0].split("-")[0].toInt(),\
                    response["Date"][j].split(" ")[0].split("-")[1].toInt(),\
                    response["Date"][j].split(" ")[0].split("-")[2].toInt()) << response["Amount"][j].toInt();
            */
            QDateTime momentInTime;
            momentInTime.setDate(QDate(response["Date"][j].split(" ")[0].split("-")[0].toInt(),\
                                        response["Date"][j].split(" ")[0].split("-")[1].toInt(),\
                                        response["Date"][j].split(" ")[0].split("-")[2].toInt()));
            series->append(momentInTime.toMSecsSinceEpoch(), response["Amount"][j].toInt());
        }

        qDebug() << "Create Graph";

        QDateTimeAxis *axisX = new QDateTimeAxis;
        axisX->setTickCount(10);
        axisX->setFormat("dd.MM.yyyy");
        axisX->setTitleText("Datum");

        Query = "SELECT IF( MIN(`Amount`) >= 50, MIN(`Amount`), 0 ) AS 'Min_Amount', MAX(`Amount`)+50 AS 'Max_Amount', ( MIN(`Date`)- INTERVAL 1 DAY ) AS 'Min_Date', IF( MAX(`Date`)+ INTERVAL 1 DAY >= CURRENT_TIMESTAMP, CURRENT_TIMESTAMP, MAX(`Date`)+ INTERVAL 1 DAY ) AS 'Max_Date' FROM `Amounts` WHERE `Item_ID` = "+item->text(0);
        response = network.getData(Query);

        axisX->setMin(QDateTime(QDate(response["Min_Date"][0].split(" ")[0].split("-")[0].toInt(),\
                                        response["Min_Date"][0].split(" ")[0].split("-")[1].toInt(),\
                                        response["Min_Date"][0].split(" ")[0].split("-")[2].toInt()),\
                                QTime(response["Min_Date"][0].split(" ")[1].split(":")[0].toInt(),\
                                        response["Min_Date"][0].split(" ")[1].split(":")[1].toInt(),\
                                        response["Min_Date"][0].split(" ")[1].split(":")[2].toInt(), 0)));

        axisX->setMax(QDateTime(QDate(response["Max_Date"][0].split(" ")[0].split("-")[0].toInt(),\
                                        response["Max_Date"][0].split(" ")[0].split("-")[1].toInt(),\
                                        response["Max_Date"][0].split(" ")[0].split("-")[2].toInt()),\
                                QTime(response["Max_Date"][0].split(" ")[1].split(":")[0].toInt(),\
                                        response["Max_Date"][0].split(" ")[1].split(":")[1].toInt(),\
                                        response["Max_Date"][0].split(" ")[1].split(":")[2].toInt(), 0)));

        QValueAxis *axisY = new QValueAxis;
        axisY->setLabelFormat("%i");
        axisY->setTitleText("Mno??stv??");

        axisY->setMin(response["Min_Amount"][0].toInt());
        axisY->setMax(response["Max_Amount"][0].toInt());


        QChart *chart = new QChart();
        chart->legend()->hide();
        chart->addSeries(series);
        chart->setTitle("Mno??stv?? polo??ek ve skladu");
        //chart->createDefaultAxes();
        chart->addAxis(axisY, Qt::AlignLeft);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisY);
        series->attachAxis(axisX);
        //series->setUseOpenGL(true);

        qDebug() << "Show Graph";

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->setParent(ui->stock_info);
        if(ui->graph->itemAt(0)!=NULL)
            ui->graph->removeItem(ui->graph->itemAt(0));
        ui->graph->addWidget(chartView);
    }
    (void) item; // dont care
    (void) column; // dont care
}
