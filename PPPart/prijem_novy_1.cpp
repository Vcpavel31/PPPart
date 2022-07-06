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

    QString Query = "SELECT `Categories`.`Name` FROM `Categories`, `Categories_Arrangement` WHERE `Categories`.`Hidden` = 0 AND `Categories`.`ID` = `Categories_Arrangement`.`Category`";
    QMap<QString, QStringList> data = network.getData(Query);
    Enabled_Categories = data["Name"];
    QCompleter *Category_Completer = new QCompleter(Enabled_Categories, this);
    Category_Completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->Kategorie_2->setCompleter(Category_Completer);

    Query = "SELECT `Supplier_Name` AS 'Name' FROM `Supplier` WHERE 1";
    data = network.getData(Query);
    Enabled_Categories = data["Name"];
    QCompleter *Distribution_Completer = new QCompleter(Enabled_Categories, this);
    Distribution_Completer->setCaseSensitivity(Qt::CaseInsensitive);
    //ui->Dodavatel_2->setCompleter(Distribution_Completer);

    Query = "SELECT `Name` FROM `Producer` WHERE 1";
    data = network.getData(Query);
    Enabled_Categories = data["Name"];
    QCompleter *Production_Completer = new QCompleter(Enabled_Categories, this);
    Production_Completer->setCaseSensitivity(Qt::CaseInsensitive);
    //ui->Vyrobce_2->setCompleter(Production_Completer);

    //ui->Hodnota_3->setCurrentIndex(4); // Default to --

    //connect(Stav_2, SIGNAL())

}

Prijem_novy_1::~Prijem_novy_1()
{
    delete ui;
}

void Prijem_novy_1::Update_list()
{
    QString Query =     "SELECT `ID`,`Name`,`EAN` FROM `Items` WHERE (`Name` LIKE '"+Nazev+"') AND "
                  +     EAN+" AND "+Vyr_cislo+Obj_cislo;
    qDebug() << Query;
    QMap<QString, QStringList> data = network.getData(Query);
    qDebug() << "Data: " << data;
    ui->tableWidget->setRowCount(0);
    if(!data.keys().contains("ID")){    //||!data.keys().contains("Name")||!data.keys().contains("EAN")
        ui->NewPart->show();
        return;
    }
    for(int i = 0; i != data["ID"].size(); i++){
        if(data["ID"].at(i).isEmpty()){
            ui->NewPart->show();
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


void Prijem_novy_1::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    QString ID = ui->tableWidget->item(index.row(), 0)->text();
    qDebug()<<ID;

    QString Query = "SELECT `Items`.`Name` AS 'Name', `Items`.`EAN` AS 'EAN', `Items`.`Product_number` AS 'Product_number', `Producer`.`Name` AS 'Producer' FROM `Items`, `Producer` WHERE `Items`.`ID` = '"+ID+"' AND `Producer`.`ID` = `Items`.`Producer`";

    QMap<QString, QStringList> data = network.getData(Query);
    qDebug() << "Data for completion" << data;
    ui->Nazev_2->setText(data["Name"][0]);
    ui->EAN_2->setText(data["EAN"][0]);
    ui->Vyr_cislo_2->setText(data["Product_number"][0]);
    //ui->Obj_cislo_2->setText(data["obj_cislo"][0]);


    /*qDebug() << "Data for vyrobce";
    if(data["Vyrobce_W"][0] != QString("")) ui->Vyrobce_2->setText(data["Vyrobce_W"][0]);
    else if(data["Vyrobce_S"][0] != QString("")){
        QString Query = "SELECT `Název` AS 'Name' FROM `Výrobci` WHERE `ID` = "+data["Vyrobce_S"][0];
        QMap<QString, QStringList> producer = network.getData(Query);
        ui->Vyrobce_2->setText(producer["Name"][0]);
    }
    else ui->Vyrobce_2->setText(QString(""));
*/

    qDebug() << "Data pro kategorie";
    Query = "SELECT `Categories`.`Name` AS 'Category_Name' FROM `Categories`, `Categories_Items` WHERE `Categories`.`ID` = `Categories_Items`.`ID` AND `Categories_Items`.`Item_ID` = "+ID;
    QMap<QString, QStringList> Category_Name = network.getData(Query);

    ui->Kategorie_2->setText(Category_Name["Category_Name"][0]);
    //qDebug() << "Enabling";
    //ui->Nazev->setEnabled(0);
    //ui->EAN->setEnabled(0);
    //ui->Obj_cislo->setEnabled(0);
    //ui->Vyr_cislo->setEnabled(0);
    //ui->New_Part->setEnabled(0);
    ui->NewPart->hide();


    qDebug() << "Showing secondary";


    ui->Umisteni->show();/*
    ui->Dodavatel->show();
    ui->Cena->show();
    ui->Stav->show();
    ui->Poznamka->show();
    ui->Polozek->show();
*/
}

void Prijem_novy_1::on_Kategorie_3_pressed()
{

    category.show();

    if(category.exec() == QDialog::Accepted){
      // You can access everything you need in dialog object
        QTreeWidgetItem item = category.getSelectedItem();
        ui->Kategorie_2->setText(item.text(0));
        categoryID = item.text(1);
    }
}


void Prijem_novy_1::on_Kategorie_2_textChanged(const QString &arg1)
{
    categoryID.clear();
    if(Enabled_Categories.indexOf(arg1) == -1) ui->Kategorie_Warning->show();
    else ui->Kategorie_Warning->hide();
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
        ui->tableWidget->show();

        ui->Umisteni->hide();


        /*
        ui->Dodavatel->hide();
        ui->Cena->hide();
        ui->Stav->hide();
        ui->Poznamka->hide();
        ui->Polozek->hide();
        */

        ui->Kategorie->setEnabled(0);
        ui->Vyrobce->setEnabled(0);
        Update_list();
    }
    else{
        ui->NewPart->hide();

        ui->tableWidget->hide();

        QCompleter *completer = new QCompleter({"Nový", "Použitý", "Poškozený", "Nefunkční"}, this);
        completer->setCaseSensitivity(Qt::CaseInsensitive);
        //ui->Stav_2->setCompleter(completer);

        ui->tableWidget->setEnabled(0);

        QString Query = "SELECT IF(`Alias` IS NULL, `Attribute_Name`, `Alias`) AS 'Name', `Type`, `ID`, `Options`, `Unit` FROM `Attributes` WHERE 1";
        QMap<QString, QStringList> response = network.getData(Query);
        qDebug() << response;

        int i = 0;
        int column_ends = 0;
        int column = 0;

        for(int j = 1; j!=response["ID"].size(); j++){ //attributes["ID"].size(); h++){

            switch(response["Type"][j].toInt()){
                case 0:
                    i--;
                    break;
                case 1:
                    pointers[response["Name"][j]]                   = new QLineEdit();

                    ui->gridLayout_2->addWidget(new QLabel(response["Name"][j]),                    i%4, column);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]],                      i%4, column+1);
                    column_ends = column+1;
                    break;
                case 2:
                    pointers[response["Name"][j]]                   = new QSpinBox();

                    ui->gridLayout_2->addWidget(new QLabel(response["Name"][j]),                    i%4, column);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]],                      i%4, column+1);
                    column_ends = column+1;
                    break;
                case 3:
                    pointers[response["Name"][j]]                   = new QPlainTextEdit();

                    ui->gridLayout_2->addWidget(new QLabel(response["Name"][j]),                    i%4, column);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]],                      i%4, column+1);
                    column_ends = column+1;
                    break;
                case 4:
                    pointers[response["Name"][j]+"_DoubleSpinBox"]  = new QDoubleSpinBox();
                    pointers[response["Name"][j]+"_ComboBox"]       = new QComboBox();
                    pointers[response["Name"][j]+"_DateEdit"]       = new QDateEdit();

                    ui->gridLayout_2->addWidget(new QLabel(response["Name"][j]),                    i%4, column);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]+"_DoubleSpinBox"],     i%4, column+1);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]+"_ComboBox"],          i%4, column+2);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]+"_DateEdit"],          i%4, column+3);

                    ComboBox = dynamic_cast<QComboBox*>(pointers[response["Name"][j]+"_ComboBox"]);
                    ComboBox->addItems(response["Options"][j].split(", "));

                    DateEdit = dynamic_cast<QDateEdit*>(pointers[response["Name"][j]+"_DateEdit"]);
                    DateEdit->setDate(QDate().currentDate());
                    DateEdit->setEnabled(false);

                    QObject::connect(pointers[response["Name"][j]+"_ComboBox"],\
                            SIGNAL(currentTextChanged(const QString &)), this,\
                            SLOT(currency_changed(const QString &)));

                    column_ends = column+3;
                    break;
                case 5:
                    pointers[response["Name"][j]+"_DoubleSpinBox"]  = new QDoubleSpinBox();
                    pointers[response["Name"][j]+"_ComboBox"]       = new QComboBox();

                    ui->gridLayout_2->addWidget(new QLabel(response["Name"][j]),                    i%4, column);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]+"_DoubleSpinBox"],     i%4, column+1);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]+"_ComboBox"],          i%4, column+2);

                    column_ends = column+2;
                    break;
                case 6:
                    pointers[response["Name"][j]]                   = new QDoubleSpinBox();

                    ui->gridLayout_2->addWidget(new QLabel(response["Name"][j]),                    i%4, column);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]],                      i%4, column+1);
                    ui->gridLayout_2->addWidget(new QLabel(response["Unit"][j]),                    i%4, column+2);
                    column_ends = column+2;
                    break;
                case 7:
                    pointers[response["Name"][j]]                   = new QDoubleSpinBox();

                    ui->gridLayout_2->addWidget(new QLabel(response["Name"][j]),                    i%4, column);
                    ui->gridLayout_2->addWidget(pointers[response["Name"][j]],                      i%4, column+1);
                    column_ends = column+1;
                    break;
            }
            i++;
            if(i%4 == 0){
                column = column_ends+1;
            }
        }




        ui->Umisteni->show();/*
        ui->Dodavatel->show();
        ui->Cena->show();
        ui->Stav->show();
        ui->Poznamka->show();
        ui->Polozek->show();
*/
        ui->Kategorie->setEnabled(1);
        ui->Vyrobce->setEnabled(1);

    }
}

// Při dvojkliku na textfield stav se zobrazí nabídka
void Prijem_novy_1::on_Stav_2_selectionChanged()
{
    //ui->Stav_2->completer()->setCompletionPrefix("");
    //ui->Stav_2->completer()->complete();
}

void Prijem_novy_1::currency_changed(const QString &text)
{
    if(text != "Kč") pointers["Cena_DateEdit"]->setEnabled(true);
    else pointers["Cena_DateEdit"]->setEnabled(false);
}
