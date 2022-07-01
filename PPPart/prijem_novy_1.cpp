#include "prijem_novy_1.h"
#include "ui_prijem_novy_1.h"



Prijem_novy_1::Prijem_novy_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Prijem_novy_1)
{
    ui->setupUi(this);

    ui->Kategorie->setEnabled(0);
    ui->Vyrobce->setEnabled(0);

    ui->Umisteni->hide();
    ui->Dodavatel->hide();
    ui->Poznamka->hide();
    ui->Stav->hide();
    ui->Cena->hide();
    ui->Polozek->hide();
    ui->Min_sklad->hide();
    ui->Delka->hide();
    ui->Pouzdro->hide();
    ui->Tolerance->hide();
    ui->Hmotnost->hide();
    ui->Hodnota->hide();
    ui->Koncovka_1->hide();
    ui->Koncovka_2->hide();
    ui->Zaporna_tolerance->hide();
    ui->Kladna_tolerance->hide();
    ui->Poc_vodicu->hide();
    ui->Material->hide();
    ui->Jme_vykon->hide();
    ui->Jme_napeti->hide();
    ui->Ozn_knihovna->hide();
    ui->Baleni->hide();
    ui->Int_oznaceni->hide();

    ui->NewPart->hide();
    ui->Kategorie_Warning->hide();

    ui->Date_exchange->setDate(QDate::currentDate());
    ui->Date_exchange->hide();
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
    ui->Dodavatel_2->setCompleter(Distribution_Completer);

    Query = "SELECT `Name` FROM `Producer` WHERE 1";
    data = network.getData(Query);
    Enabled_Categories = data["Name"];
    QCompleter *Production_Completer = new QCompleter(Enabled_Categories, this);
    Production_Completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->Vyrobce_2->setCompleter(Production_Completer);

    ui->Hodnota_3->setCurrentIndex(4); // Default to --

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
    if(!data.keys().contains("ID")||!data.keys().contains("Name")||!data.keys().contains("EAN")){
        qDebug() << "Didnt get ID, Name or EAN";
        ui->NewPart->show();
        ui->pushButton->show();
        return;
    }
    for(int i = 0; i != data["ID"].size(); i++){
        if(!data["ID"].at(i).isEmpty()){
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(data["ID"].at(i)));
            ui->NewPart->hide();
            ui->pushButton->hide();
        }
        else{
            qDebug() << "ERROR: didnt receive ID";
            ui->NewPart->show();
            ui->pushButton->show();
        }

        if(!data["Name"].at(i).isEmpty()) ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(data["Name"].at(i)));
        else qDebug() << "ERROR: didnt receive Name";

        if(!data["EAN"].at(i).isEmpty()) ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(data["EAN"].at(i)));
        else qDebug() << "ERROR: didnt receive EAN";
    }
    ui->tableWidget->update();
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
    ui->pushButton->hide();




    qDebug() << "Showing secondary";


    ui->Umisteni->show();
    ui->Dodavatel->show();
    ui->Cena->show();
    ui->Stav->show();
    ui->Poznamka->show();
    ui->Polozek->show();

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
        //ui->pushButton->show();
        //ui->NewPart->show();

        ui->tableWidget->setEnabled(1);
        ui->tableWidget->show();

        ui->Umisteni->hide();
        ui->Dodavatel->hide();
        ui->Cena->hide();
        ui->Stav->hide();
        ui->Poznamka->hide();
        ui->Polozek->hide();

        ui->Kategorie->setEnabled(0);
        ui->Vyrobce->setEnabled(0);

    }
    else{
        //ui->pushButton->hide();
        //ui->NewPart->hide();

        ui->tableWidget->hide();

        QCompleter *completer = new QCompleter({"Nový", "Použitý", "Poškozený", "Nefunkční"}, this);
        completer->setCaseSensitivity(Qt::CaseInsensitive);
        ui->Stav_2->setCompleter(completer);

        ui->tableWidget->setEnabled(0);

        ui->Umisteni->show();
        ui->Dodavatel->show();
        ui->Cena->show();
        ui->Stav->show();
        ui->Poznamka->show();
        ui->Polozek->show();

        ui->Kategorie->setEnabled(1);
        ui->Vyrobce->setEnabled(1);

    }
}

// Při dvojkliku na textfield stav se zobrazí nabídka
void Prijem_novy_1::on_Stav_2_selectionChanged()
{
    ui->Stav_2->completer()->setCompletionPrefix("");
    ui->Stav_2->completer()->complete();
}

void Prijem_novy_1::on_Currency_currentTextChanged(const QString &arg1)
{
    if(arg1 != "Kč") ui->Date_exchange->show();
    else ui->Date_exchange->hide();
}
