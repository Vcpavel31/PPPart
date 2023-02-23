#include "prijem_novy_1.h"
#include "ui_prijem_novy_1.h"

Prijem_novy_1::Prijem_novy_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Prijem_novy_1)
{
    ui->setupUi(this);

    ui->Kategorie->setEnabled(0);
    ui->Vyrobce->setEnabled(0);

    ui->NewPart->hide();
    ui->Kategorie_Warning->hide();

    Update_list();

    QString Query = "SELECT `Categories`.`Name` AS 'Name', `Categories`.`ID` AS 'ID' FROM `Categories`, `Categories_Arrangement` WHERE `Categories`.`Hidden` = 0 AND `Categories`.`ID` = `Categories_Arrangement`.`Category`";
    QMap<QString, QStringList> data = network.getData(Query);
    Enabled_Categories = data["Name"];
    for(int i = 0; i != data["ID"].size();i++){
        Categories[data["Name"][i]] = data["ID"][i].toInt();
    }
    QCompleter *Category_Completer = new QCompleter(Enabled_Categories, this);
    Category_Completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->Kategorie_2->setCompleter(Category_Completer);
/*
    Query = "SELECT `Supplier_Name` AS 'Name' FROM `Supplier` WHERE 1";
    data = network.getData(Query);
    Enabled_Categories = data["Name"];
    QCompleter *Distribution_Completer = new QCompleter(Enabled_Categories, this);
    Distribution_Completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->Dodavatel_2->setCompleter(Distribution_Completer);
*/
    Query = "SELECT `Name` FROM `Producer` WHERE 1";
    data = network.getData(Query);
    QList Producers = data["Name"];
    QCompleter *Production_Completer = new QCompleter(Producers, this);
    Production_Completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->Vyrobce_2->setCompleter(Production_Completer);

}

Prijem_novy_1::~Prijem_novy_1()
{
    delete ui;
}

void Prijem_novy_1::Update_list()
{
    QString Query = "SELECT `ID`,`Name`,`EAN` FROM `Items` WHERE (`Name` LIKE '"+Nazev+"') AND "+EAN+" AND "+Int_cislo+" AND "+Vyr_cislo+Obj_cislo;
    qDebug() << Query;
    QMap<QString, QStringList> data = network.getData(Query);
    qDebug() << "Data: " << data;
    ui->tableWidget->setRowCount(0);
    if(!data.keys().contains("ID")){    //||!data.keys().contains("Name")||!data.keys().contains("EAN")
        if(ui->New_Part->checkState() == 0){
            ui->NewPart->show();
        }
        return;
    }
    for(int i = 0; i != data["ID"].size(); i++){
        if(data["ID"].at(i).isEmpty()){
            if(ui->New_Part->checkState() == 0){
                ui->NewPart->show();
            }
        }
        else{
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(data["ID"].at(i)));
            ui->NewPart->hide();
        }

        if(!data["Name"].at(i).isEmpty()) ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(data["Name"].at(i)));
        else qDebug() << "ERROR: didnt receive Name";

        if(!data["EAN"].at(i).isEmpty()) ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(data["EAN"].at(i)));
        else qDebug() << "ERROR: didnt receive EAN";
    }
    ui->tableWidget->update();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setColumnHidden(0, 1); // Hide ID Column for usability
}

void Prijem_novy_1::on_Nazev_2_textChanged(const QString &arg1)
{
    if(arg1 == "") Nazev = "%";
    else Nazev = "%"+arg1+"%";
    Update_list();
}


void Prijem_novy_1::on_EAN_2_textChanged(const QString &arg1)
{
    if(arg1 == "") EAN = "(`EAN` LIKE '%' OR `EAN` IS NULL)";
    else EAN = "(`EAN` LIKE '%"+arg1+"%')";;
    Update_list();
}


void Prijem_novy_1::on_Obj_cislo_2_textChanged(const QString &arg1)
{
    if(arg1 == "") Obj_cislo = "";
    else Obj_cislo = " AND `ID` IN (SELECT `Item_ID` FROM `Suppliers` WHERE (`Supplier_Code` LIKE '%"+arg1+"%'))";;
    Update_list();
}


void Prijem_novy_1::on_Vyr_cislo_2_textChanged(const QString &arg1)
{
    if(arg1 == "") Vyr_cislo = "(`Product_number` LIKE '%' OR `Product_number` IS NULL)";
    else Vyr_cislo = "(`Product_number` LIKE '%"+arg1+"%')";;
    Update_list();
}

void Prijem_novy_1::on_Interni_cislo_2_textChanged(const QString &arg1)
{
    if(arg1 == "") Int_cislo = "(`Internal_marking` LIKE '%' OR `Internal_marking` IS NULL)";
    else Int_cislo = "(`Internal_marking` LIKE '%"+arg1+"%')";;
    Update_list();
}

void Prijem_novy_1::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    QString ID = ui->tableWidget->item(index.row(), 0)->text();
    qDebug()<<ID;

    QString Query = "SELECT `Items`.`Name` AS 'Name', `Items`.`EAN` AS 'EAN', `Items`.`Product_number` AS 'Product_number', `Producer`.`Name` AS 'Producer', `Items`.`Internal_marking` AS 'Internal_marking' FROM `Items`, `Producer` WHERE `Items`.`ID` = '"+ID+"' AND `Producer`.`ID` = `Items`.`Producer`";

    QMap<QString, QStringList> data = network.getData(Query);
    qDebug() << "Data for completion" << data;
    ui->Nazev_2->setText(data["Name"][0]);
    ui->EAN_2->setText(data["EAN"][0]);
    ui->Vyr_cislo_2->setText(data["Product_number"][0]);
    ui->Interni_cislo_2->setText(data["Internal_marking"][0]);

    qDebug() << "Data pro kategorie";
    Query = "SELECT `Categories`.`Name` AS 'Category_Name',  `Categories`.`ID` AS 'Category_ID' FROM `Categories`, `Categories_Items` WHERE `Categories`.`ID` = `Categories_Items`.`Category_ID` AND `Categories_Items`.`Item_ID` = "+ID;
    qDebug() << Query;
    QMap<QString, QStringList> Category_Name = network.getData(Query);
    categoryID = Category_Name["Category_ID"][0].toInt();
    qDebug() << " KATEGORIE              " << categoryID;
    ui->Kategorie_2->setText(Category_Name["Category_Name"][0]);

    ui->NewPart->hide();


    /////// TODO
   // create_input();


    qDebug() << "Showing secondary";


    ui->Umisteni->show();
}

void Prijem_novy_1::on_Kategorie_3_pressed()
{

    category.show();

    if(category.exec() == QDialog::Accepted){
      // You can access everything you need in dialog object
        QTreeWidgetItem item = category.getSelectedItem();
        ui->Kategorie_2->setText(item.text(0));
        //int what = categoryID = Categories[item.text(1)]; // do not use... return 0 idk why
    }
}


void Prijem_novy_1::on_Kategorie_2_textChanged(const QString &arg1)
{
    qDebug() << arg1 << ":  " << Enabled_Categories.indexOf(arg1) << " IN: " << Enabled_Categories;
    if(Enabled_Categories.indexOf(arg1) == -1){
        ui->Kategorie_Warning->show();
        categoryID = -1;
    }
    else{
        ui->Kategorie_Warning->hide();
        categoryID = Categories[arg1];
        if(ui->New_Part->checkState()) create_input();
    }
}

void Prijem_novy_1::on_pushButton_pressed()
{
    ui->New_Part->setChecked(true);

}

// Nová součástka ???
void Prijem_novy_1::on_New_Part_stateChanged(int arg1)
{
    qDebug()<<arg1;
    if(!arg1){
        ui->tableWidget->setEnabled(1);
        //ui->tableWidget->show();
        ui->verticalWidget->show();

        ui->Umisteni->hide();

        ui->Kategorie->setEnabled(0);
        ui->Vyrobce->setEnabled(0);
        Update_list();
    }
    else{
        if(categoryID != -1) create_input();

        ui->NewPart->hide();
        //ui->tableWidget->hide();
        ui->verticalWidget->hide();

        ui->tableWidget->setEnabled(0);
        ui->Kategorie->setEnabled(1);
        ui->Vyrobce->setEnabled(1);

        ui->Umisteni->show();
    }
}

void Prijem_novy_1::set_ComboBox(QMap<QString, QStringList> response, QMap<QString, QWidget*> pointers, int j){
    if(response["Options_Type"][j] == "0"){
        dynamic_cast<QComboBox*>(pointers[response["Name"][j]+"_ComboBox"])->addItems(response["Options"][j].split(", "));
        // Options_Selected
        //qDebug() << response["Options_Selected"][j].toInt();
        dynamic_cast<QComboBox*>(pointers[response["Name"][j]+"_ComboBox"])->setCurrentIndex(response["Options_Selected"][j].toInt());
    }
    else{
        //Get Query of response["Options"][j] and response parse as Items for QComboBox
    }
}

void Prijem_novy_1::set_Helper(QMap<QString, QStringList> response, int j){
    if(response["Helper"][j] == "1"){

        QCompleter *Completer;
        //qDebug() << j; qDebug() << response["Helper"][j]; qDebug() << response["Helper_Querry"][j]; qDebug() << response["Helper_Type"][j];
        if(response["Helper_Type"][j] == "1"){
            QMap<QString, QStringList> data = network.getData(response["Helper_Querry"][j]);
            Completer = new QCompleter(data["Name"], this);
        }
        if(response["Helper_Type"][j] == "0"){
            Completer = new QCompleter(response["Helper_Querry"][j].split(", "), this);
        }

        Completer->setCaseSensitivity(Qt::CaseInsensitive);
        dynamic_cast<QLineEdit*>(pointers[response["Name"][j]])->setCompleter(Completer);
    }
}

void Prijem_novy_1::currency_changed(const QString &text)
{
    if(text != "Kč") pointers["Cena_DateEdit"]->setEnabled(true);
    else pointers["Cena_DateEdit"]->setEnabled(false);
}

void Prijem_novy_1::create_input(){

    QString Query = "SELECT `Attributes`.`ID` AS 'ID', IF( `Attributes`.`Alias` IS NULL, `Attributes`.`Attribute_Name`, `Attributes`.`Alias` ) AS 'Name', \
`Attributes`.`Writable` AS 'Writable', `Attributes`.`Type` AS 'Type',`Attributes`.`Unit` AS 'Unit', `Attributes`.`Default_Value` AS 'Default_Value',\
`Attributes`.`Options_Type` AS 'Options_Type', `Attributes`.`Options` AS 'Options',`Attributes`.`Options_Selected` AS 'Options_Selected',`Attributes`.`Helper_Type` AS 'Helper_Type',\
`Attributes`.`Helper_Querry` AS 'Helper_Querry',`Attributes`.`Helper` AS 'Helper' FROM `Attributes`, `Categories_Attributes`\
WHERE `Categories_Attributes`.`Category` = '"+QString::number(categoryID)+"' AND `Attributes`.`Writable` = '1' AND `Categories_Attributes`.`Attributes` = `Attributes`.`ID`";


    qDebug() << Query;
    QMap<QString, QStringList> response = network.getData(Query);
    qDebug() << response;
    if(!response.isEmpty()){
        int i = 0;
        int column_ends = 0;
        int column = 0;


        // remove all previous items if there are any
        QLayoutItem* item;
        while ( ( item = ui->gridLayout_2->takeAt( 0 ) ) != NULL )
        {
            qDebug() << "Removing items\n";
            delete item->widget();
        }

        //clear whole pointer QMap
        for (auto it = pointers.begin(); it != pointers.end();)
        {
            it = pointers.erase(it);
        }

        for(int j = 0; j!=response["ID"].size(); j++){ //attributes["ID"].size(); h++){

            switch(response["Type"][j].toInt()){
                case 0:
                    i--;
                break;
                case 1:
                    pointers[response["Name"][j]] = new QLineEdit();

                    ui->gridLayout_2->addWidget(new QLabel(response["Name"][j]), i%rows, column);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]], i%rows, column+1);

                    set_Helper(response, j);
                    if(column_ends < column+1) column_ends = column+1;
                break;
                case 2:
                    pointers[response["Name"][j]] = new QSpinBox();

                    ui->gridLayout_2->addWidget(new QLabel(response["Name"][j]), i%rows, column);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]], i%rows, column+1);
                    if(column_ends < column+1) column_ends = column+1;
                break;
                case 3:
                    pointers[response["Name"][j]] = new QPlainTextEdit();

                    ui->gridLayout_2->addWidget(new QLabel(response["Name"][j]), i%rows, column);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]], i%rows, column+1);
                    if(column_ends < column+1) column_ends = column+1;
                break;
                case 4: // Currency
                    pointers[response["Name"][j]+"_DoubleSpinBox"] = new QDoubleSpinBox();
                    pointers[response["Name"][j]+"_ComboBox"] = new QComboBox();
                    pointers[response["Name"][j]+"_DateEdit"] = new QDateEdit();

                    ui->gridLayout_2->addWidget(new QLabel(response["Name"][j]), i%rows, column);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]+"_DoubleSpinBox"], i%rows, column+1);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]+"_ComboBox"], i%rows, column+2);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]+"_DateEdit"], i%rows, column+3);

                    dynamic_cast<QDoubleSpinBox*>(pointers[response["Name"][j]+"_DoubleSpinBox"])->setMaximum(999999.99);

                    QObject::connect(pointers[response["Name"][j]+"_ComboBox"], SIGNAL(currentTextChanged(const QString &)), this, SLOT(currency_changed(const QString &)));
                    dynamic_cast<QDateEdit*>(pointers[response["Name"][j]+"_DateEdit"])->setEnabled(false);
                    dynamic_cast<QDateEdit*>(pointers[response["Name"][j]+"_DateEdit"])->setMaximumDate(QDate().currentDate());

                    set_ComboBox(response, pointers, j);

                    dynamic_cast<QDateEdit*>(pointers[response["Name"][j]+"_DateEdit"])->setDate(QDate().currentDate());
                    if(column_ends < column+3) column_ends = column+3;
                break;
                case 5:
                    pointers[response["Name"][j]+"_DoubleSpinBox"]  = new QDoubleSpinBox();
                    pointers[response["Name"][j]+"_ComboBox"]       = new QComboBox();

                    ui->gridLayout_2->addWidget(new QLabel(response["Name"][j]), i%rows, column);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]+"_DoubleSpinBox"], i%rows, column+1);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]+"_ComboBox"], i%rows, column+2);

                    dynamic_cast<QDoubleSpinBox*>(pointers[response["Name"][j]+"_DoubleSpinBox"])->setMaximum(999999.99);

                    set_ComboBox(response, pointers, j);

                    if(column_ends < column+2) column_ends = column+2;
                break;
                case 6:
                    pointers[response["Name"][j]] = new QDoubleSpinBox();

                    ui->gridLayout_2->addWidget(new QLabel(response["Name"][j]), i%rows, column);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]], i%rows, column+1);
                    ui->gridLayout_2->addWidget(new QLabel(response["Unit"][j]), i%rows, column+2);

                    dynamic_cast<QDoubleSpinBox*>(pointers[response["Name"][j]])->setMaximum(999999.99);
                    dynamic_cast<QDoubleSpinBox*>(pointers[response["Name"][j]])->setValue(response["Default_Value"][j].toDouble());

                    if(column_ends < column+2) column_ends = column+2;
                break;
                case 7:
                    pointers[response["Name"][j]] = new QDoubleSpinBox();

                    ui->gridLayout_2->addWidget(new QLabel(response["Name"][j]), i%rows, column);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]], i%rows, column+1);

                    dynamic_cast<QDoubleSpinBox*>(pointers[response["Name"][j]+"_DoubleSpinBox"])->setMaximum(999999.99);

                    if(column_ends < column+1) column_ends = column+1;
                break;
                case 8:
                    pointers[response["Name"][j]+"_ComboBox"] = new QComboBox();

                    ui->gridLayout_2->addWidget(new QLabel(response["Name"][j]), i%rows, column);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]+"_ComboBox"], i%rows, column+1);

                    set_ComboBox(response, pointers, j);

                    if(column_ends < column+1) column_ends = column+1;
                break;
                case 9:
                    pointers[response["Name"][j]+"_PushButton"] = new QPushButton();

                    //QColor color
                    ui->gridLayout_2->addWidget(new QLabel(response["Name"][j]), i%rows, column);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]+"_PushButton"], i%rows, column+1);

                    dynamic_cast<QPushButton*>(pointers[response["Name"][j]+"_PushButton"])->setStyleSheet(COLOR_STYLE.arg(color.name()).arg(getIdealTextColor(color).name()));

                    if(column_ends < column+1) column_ends = column+1;
                break;
                case 10: // Tolerance
                    pointers[response["Name"][j]] = new QDoubleSpinBox();
                    pointers[response["Name"][j]+"-"] = new QDoubleSpinBox();
                    pointers[response["Name"][j]+"+"] = new QDoubleSpinBox();

                    pointers[response["Name"][j]+"_Toleration"] = new QLabel("Tolerance");
                    pointers[response["Name"][j]+"_Toleration-"] = new QLabel("Záporná Tolerance");
                    pointers[response["Name"][j]+"_Toleration+"] = new QLabel("Kladná Tolerance");
                    pointers[response["Name"][j]+"_Unit"] = new QLabel(response["Unit"][j]);

                    pointers[response["Name"][j]+"_ToolButton"] = new QToolButton();

                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]+"_Toleration"], i%rows, column);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]], i%rows, column+2);

                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]+"_Toleration-"], i%rows, column+4);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]+"-"], i%rows, column+5);

                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]+"_Toleration+"], i%rows, column+6);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]+"+"], i%rows, column+7);

                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]+"_Unit"], i%rows, column+3); // %
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]+"_ToolButton"], i%rows, column+1);

                    QObject::connect(pointers[response["Name"][j]+"_ToolButton"], SIGNAL(pressed()), this, SLOT(Showtolerances()));

                    dynamic_cast<QToolButton*>(pointers[response["Name"][j]+"_ToolButton"])->setText("+/-");
                    dynamic_cast<QDoubleSpinBox*>(pointers[response["Name"][j]+"-"])->setMaximum(100.00);
                    dynamic_cast<QDoubleSpinBox*>(pointers[response["Name"][j]+"+"])->setMaximum(100.00);
                    dynamic_cast<QDoubleSpinBox*>(pointers[response["Name"][j]+"-"])->setHidden(1);
                    dynamic_cast<QDoubleSpinBox*>(pointers[response["Name"][j]+"+"])->setHidden(1);
                    dynamic_cast<QLabel*>(pointers[response["Name"][j]+"_Toleration-"])->setVisible(0);
                    dynamic_cast<QLabel*>(pointers[response["Name"][j]+"_Toleration+"])->setVisible(0);
                    dynamic_cast<QDoubleSpinBox*>(pointers[response["Name"][j]])->setMaximum(100.00);
                    dynamic_cast<QDoubleSpinBox*>(pointers[response["Name"][j]])->setValue(response["Default_Value"][j].toDouble());
                    Tolaration_name = response["Name"][j];
                    if(column_ends < column+7) column_ends = column+7;
                break;

            }
            i++;
            if(i%rows == 0){
                column = column_ends+1;
            }

            if(response["Name"][j] == "Barva"){
                QObject::connect(pointers["Barva_PushButton"], SIGNAL(pressed()), this, SLOT(ColorPick()));
            }
        }
    }
    else qDebug() << "Category: " << categoryID << " is not defined!";
}

void Prijem_novy_1::Showtolerances(){

    if(dynamic_cast<QDoubleSpinBox*>(pointers[Tolaration_name+"-"])->isHidden()){

        dynamic_cast<QDoubleSpinBox*>(pointers[Tolaration_name])->setHidden(1);
        dynamic_cast<QLabel*>(pointers[Tolaration_name+"_Unit"])->setVisible(0);

        dynamic_cast<QLabel*>(pointers[Tolaration_name+"_Toleration-"])->setVisible(1);
        dynamic_cast<QDoubleSpinBox*>(pointers[Tolaration_name+"-"])->setHidden(0);
        dynamic_cast<QLabel*>(pointers[Tolaration_name+"_Toleration+"])->setVisible(1);
        dynamic_cast<QDoubleSpinBox*>(pointers[Tolaration_name+"+"])->setHidden(0);

    }
    else{

        dynamic_cast<QDoubleSpinBox*>(pointers[Tolaration_name])->setHidden(0);
        dynamic_cast<QLabel*>(pointers[Tolaration_name+"_Unit"])->setVisible(1);

        dynamic_cast<QLabel*>(pointers[Tolaration_name+"_Toleration-"])->setVisible(0);
        dynamic_cast<QDoubleSpinBox*>(pointers[Tolaration_name+"-"])->setHidden(1);
        dynamic_cast<QLabel*>(pointers[Tolaration_name+"_Toleration+"])->setVisible(0);
        dynamic_cast<QDoubleSpinBox*>(pointers[Tolaration_name+"+"])->setHidden(1);

    }

}

void Prijem_novy_1::ColorPick(){
    Pick_Color_Window.show();
    if(Pick_Color_Window.exec() == QDialog::Accepted){
       // You can access everything you need in dialog object
        color = Pick_Color_Window.getColor();
        QColor IdealTextColor = getIdealTextColor(color);

        dynamic_cast<QPushButton*>(pointers["Barva_PushButton"])->setStyleSheet(COLOR_STYLE.arg(color.name()).arg(IdealTextColor.name()));
    }
}

//==============================================================================
//  Nom : getIdealTextColor
//! @return an ideal label color, based on the given background color.
//! Based on http://www.codeproject.com/cs/media/IdealTextColor.asp
//==============================================================================
QColor Prijem_novy_1::getIdealTextColor(const QColor rBackgroundColor){
    const int THRESHOLD = 105;
    int BackgroundDelta = (rBackgroundColor.red() * 0.299) + (rBackgroundColor.green() * 0.587) + (rBackgroundColor.blue() * 0.114);
    return QColor((255- BackgroundDelta < THRESHOLD) ? Qt::black : Qt::white);
}

float Prijem_novy_1::Money_Conversion(QDate date, QString currency, float value){
    qDebug() << "Currency: " << date << value << currency << "\n";
    return 738.60;
}

void Prijem_novy_1::send_DB(){

    QString Query = "SELECT `Attributes`.`ID` AS 'ID', IF( `Attributes`.`Alias` IS NULL, `Attributes`.`Attribute_Name`, `Attributes`.`Alias` ) AS 'Name', `Attributes`.`Writable` AS 'Writable', `Attributes`.`Type` AS 'Type'\
FROM `Attributes`, `Categories_Attributes` WHERE `Categories_Attributes`.`Category` = '"+QString::number(categoryID)+"' AND `Attributes`.`Writable` = '1' AND `Categories_Attributes`.`Attributes` = `Attributes`.`ID`";
    qDebug() << Query;
    QMap<QString, QStringList> response = network.getData(Query);
    qDebug() << response;

    if(!response.isEmpty()){
        int inserted_item_ID = 0;
        if(true){ ////// If adding new part

            // First check producer
            QString Query = "SELECT `ID` FROM `Producer` WHERE `Name` ='"+ui->Vyrobce_2->text()+"'";
            //qDebug() << Query;
            QMap<QString, QStringList> response_producer = network.getData(Query);
            //qDebug() << response_producer;

            int Producer_ID;

            if(response_producer.isEmpty()){
                QString Query = "INSERT INTO `Producer`(`Name`) VALUES ('"+ui->Vyrobce_2->text()+"')";
                qDebug() << Query;
                //network.pushData(Query);
                Query = "SELECT `ID` FROM `Producer` WHERE `Name` ='"+ui->Vyrobce_2->text()+"'";
                response_producer = network.getData(Query);
                Producer_ID = response_producer["ID"][0].toInt();
            }
            else{
                Producer_ID = response_producer["ID"][0].toInt();
            }

            qDebug() << "Výrobce: ID: " << Producer_ID;



            Query = "INSERT INTO `Items`(`Name`, `EAN`, `Product_number`, `Producer`, `Internal_marking`)\
VALUES ('"+ui->Nazev_2->text()+"','"+ui->EAN_2->text()+"','"+ui->Vyr_cislo_2->text()+"','"+QString::number(Producer_ID)+"','"+ui->Interni_cislo_2->text()+"')";
            //qDebug() << Query;
            network.pushData(Query);
            Query = "SELECT `ID` FROM `Items` WHERE `Name` = '"+ui->Nazev_2->text()+"' AND `EAN` = '"+ui->EAN_2->text()+"' AND\
`Product_number` = '"+ui->Vyr_cislo_2->text()+"' AND `Producer` = '"+QString::number(Producer_ID)+"' AND `Internal_marking` = '"+ui->Interni_cislo_2->text()+"'";
            QMap<QString, QStringList> inserted_item = network.getData(Query);
            inserted_item_ID = inserted_item["ID"][0].toInt();

            //qDebug() << "ID vložené položky" << inserted_item_ID;
            qDebug() << "Položka číslo: " << inserted_item_ID << "vložena do kategorie: " << categoryID << network.getData("INSERT INTO `Categories_Items`(`Item_ID`, `Category_ID`) VALUES ('"+QString::number(inserted_item_ID)+"','"+QString::number(categoryID)+"')");

        }
        for(int j = 0; j!=response["ID"].size(); j++){ //attributes["ID"].size(); h++){
            if(response["Writable"][j] != "0"){
                //qDebug() << response["Type"][j];
                switch(response["Type"][j].toInt()){
                    case 1:
                        qDebug() << "Vložen atribut 1: " << response["Name"][j] << response["ID"][j];
                        network.pushData("INSERT INTO `Attribute`(`Item_ID`, `Attribute_Option`, `Attribute_Value`, `Attribute_Info`, `Attribute_Date`) VALUES ('"+QString::number(inserted_item_ID)+"','"+response["ID"][j]+"','"+dynamic_cast<QLineEdit*>(pointers[response["Name"][j]])->text()+"',NULL,NULL)");
                    break;
                    case 2:
                        qDebug() << "Vložen atribut 2: " << response["Name"][j] << response["ID"][j];
                        network.pushData("INSERT INTO `Attribute`(`Item_ID`, `Attribute_Option`, `Attribute_Value`, `Attribute_Info`, `Attribute_Date`) VALUES ('"+QString::number(inserted_item_ID)+"','"+response["ID"][j]+"','"+dynamic_cast<QSpinBox*>(pointers[response["Name"][j]])->text()+"',NULL,NULL)");
                    break;
                    case 3:
                        qDebug() << "Vložen atribut 3: " << response["Name"][j] << response["ID"][j];
                        network.pushData("INSERT INTO `Attribute`(`Item_ID`, `Attribute_Option`, `Attribute_Value`, `Attribute_Info`, `Attribute_Date`) VALUES ('"+QString::number(inserted_item_ID)+"','"+response["ID"][j]+"','"+dynamic_cast<QPlainTextEdit*>(pointers[response["Name"][j]])->toPlainText()+"',NULL,NULL)");
                    break;

                    case 4:
                        qDebug() << "Vložen atribut 4: " << response["Name"][j] << response["ID"][j];
                        if(dynamic_cast<QComboBox*>(pointers[response["Name"][j]+"_ComboBox"])->currentText() != "Kč"){
                            float value = dynamic_cast<QDoubleSpinBox*>(pointers[response["Name"][j]+"_DoubleSpinBox"])->value();
                            QString currency = dynamic_cast<QComboBox*>(pointers[response["Name"][j]+"_ComboBox"])->currentText();
                            QDate date = dynamic_cast<QDateEdit*>(pointers[response["Name"][j]+"_DateEdit"])->date();
                            price_Kc = Money_Conversion(date, currency, value);
                            //qDebug() << response["Name"][j] << price_Kc << "INSERT INTO `Attribute`(`Item_ID`, `Attribute_Option`, `Attribute_Value`, `Attribute_Info`, `Attribute_Date`) VALUES ('"+QString::number(inserted_item_ID)+"','"+response["ID"][j]+"','"+QString::number(price_Kc)+"','"+QString::number(value)+" "+currency+"','"+date.toString("yyyy-MM-dd")+" 00:00:00')";
                            network.pushData("INSERT INTO `Attribute`(`Item_ID`, `Attribute_Option`, `Attribute_Value`, `Attribute_Info`, `Attribute_Date`) VALUES ('"+QString::number(inserted_item_ID)+"','"+response["ID"][j]+"','"+QString::number(price_Kc)+"','"+QString::number(value)+" "+currency+"','"+date.toString("yyyy-MM-dd")+" 00:00:00')");
                        }
                        else{
                            price_Kc = dynamic_cast<QDoubleSpinBox*>(pointers[response["Name"][j]+"_DoubleSpinBox"])->value();
                            //qDebug() << response["Name"][j] << price_Kc << "INSERT INTO `Attribute`(`Item_ID`, `Attribute_Option`, `Attribute_Value`, `Attribute_Info`, `Attribute_Date`) VALUES ('"+QString::number(inserted_item_ID)+"','"+response["ID"][j]+"','"+QString::number(price_Kc)+"',NULL,NULL)";
                            network.pushData("INSERT INTO `Attribute`(`Item_ID`, `Attribute_Option`, `Attribute_Value`, `Attribute_Info`, `Attribute_Date`) VALUES ('"+QString::number(inserted_item_ID)+"','"+response["ID"][j]+"','"+QString::number(price_Kc)+"',NULL,NULL)");

                        }
                    break;



                    case 5:
                        qDebug() << "Vložen atribut 5: " << response["Name"][j] << response["ID"][j];
                        network.pushData("INSERT INTO `Attribute`(`Item_ID`, `Attribute_Option`, `Attribute_Value`, `Attribute_Info`, `Attribute_Date`) VALUES ('"+QString::number(inserted_item_ID)+"','"+response["ID"][j]+"','"+QString::number(dynamic_cast<QDoubleSpinBox*>(pointers[response["Name"][j]+"_DoubleSpinBox"])->value())+"','"+dynamic_cast<QComboBox*>(pointers[response["Name"][j]+"_ComboBox"])->currentText()+"',NULL)");
                    break;
                    case 6:
                        qDebug() << "Vložen atribut 6: " << response["Name"][j] << response["ID"][j];
                        network.pushData("INSERT INTO `Attribute`(`Item_ID`, `Attribute_Option`, `Attribute_Value`, `Attribute_Info`, `Attribute_Date`) VALUES ('"+QString::number(inserted_item_ID)+"','"+response["ID"][j]+"','"+QString::number(dynamic_cast<QDoubleSpinBox*>(pointers[response["Name"][j]])->value())+"',NULL,NULL)");
                    break;
                    case 7:
                        qDebug() << "Vložen atribut 7: " << response["Name"][j] << response["ID"][j];
                        network.pushData("INSERT INTO `Attribute`(`Item_ID`, `Attribute_Option`, `Attribute_Value`, `Attribute_Info`, `Attribute_Date`) VALUES ('"+QString::number(inserted_item_ID)+"','"+response["ID"][j]+"','"+QString::number(dynamic_cast<QDoubleSpinBox*>(pointers[response["Name"][j]])->value())+"',NULL,NULL)");
                    break;
                    case 8:
                        qDebug() << "Vložen atribut 8: " << response["Name"][j] << response["ID"][j];
                        network.pushData("INSERT INTO `Attribute`(`Item_ID`, `Attribute_Option`, `Attribute_Value`, `Attribute_Info`, `Attribute_Date`) VALUES ('"+QString::number(inserted_item_ID)+"','"+response["ID"][j]+"','"+dynamic_cast<QComboBox*>(pointers[response["Name"][j]+"_ComboBox"])->currentText()+"',NULL,NULL)");
                    break;
                    case 9:
                        qDebug() << "Nedokončený atribut 9: " << response["Name"][j] << response["ID"][j];
                        ////// MAGIC work with COLOR
                    break;
                    case 10: // Tolerance
                        qDebug() << "Nedokončený atribut 10: " << response["Name"][j] << response["ID"][j];
                        ////// MAGIC work with toleration
                    break;
                }
            }
        }

    }

}

void Prijem_novy_1::on_Next_part_pressed()
{
    send_DB();
    // Reload empty this window
}


void Prijem_novy_1::on_Done_pressed()
{
    send_DB();
    // Close this window and empty it for new part later
}
