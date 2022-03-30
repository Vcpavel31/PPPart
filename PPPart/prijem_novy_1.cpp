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

    ui->Date_exchange->setDate(QDate::currentDate());
    ui->Date_exchange->hide();
    Update_list();

    QString Query = "SELECT `Nazev` AS 'Name' FROM `Kategorie` WHERE `ID` IN (SELECT `Kategorie` FROM `Usporadani_kategorii` WHERE `Uzivatel` = 1)";
    QMap<QString, QStringList> data = network.getData(Query);

    QCompleter *Category_Completer = new QCompleter(data["Name"], this);
    Category_Completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->Kategorie_2->setCompleter(Category_Completer);
      
    ui->Hodnota_3->setCurrentIndex(4); // Default to --

    //connect(Stav_2, SIGNAL())

}

Prijem_novy_1::~Prijem_novy_1()
{
    delete ui;
}

void Prijem_novy_1::Update_list()
{

    QString Query = "SELECT Nazev.ID AS 'ID',Nazev.Název AS 'Name',EAN.EAN AS 'EAN' FROM Interni_ID Nazev, EAN EAN WHERE Nazev.ID = EAN.Interni_ID AND Nazev.Název LIKE '"+Nazev+"' AND Nazev.ID IN (\
                SELECT `Interni_ID` FROM `Objednací číslo` WHERE "+Obj_cislo+" AND `Interni_ID` IN (\
                SELECT `Interni_ID` FROM `EAN` WHERE "+EAN+"  AND `Interni_ID` IN (\
                SELECT `Interni_ID` FROM `Číslo výrobce` WHERE "+Vyr_cislo+" ) ) )";


    QMap<QString, QStringList> data = network.getData(Query);
    qDebug() << "Data: " << data;
    ui->tableWidget->setRowCount(0);
    if(!data.keys().contains("ID")||!data.keys().contains("Name")||!data.keys().contains("EAN"))
        {
            qDebug() << "Didnt get ID, Name or EAN";
            ui->NewPart->show();
            return;
    }
    for(int i = 0; i != data["ID"].size(); i++)
    {
        if(!data["ID"].at(i).isEmpty())
          {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(data["ID"].at(i)));
            ui->NewPart->hide();
        }
        else
            {
                qDebug() << "ERROR: didnt receive ID";
                ui->NewPart->show();
        }

        if(!data["Name"].at(i).isEmpty())
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(data["Name"].at(i)));
        else
            qDebug() << "ERROR: didnt receive Name";

        if(!data["EAN"].at(i).isEmpty())
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(data["EAN"].at(i)));
        else
            qDebug() << "ERROR: didnt receive EAN";
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
    if(arg1 == "") Obj_cislo = "(`Objednací číslo` LIKE '%' OR `Objednací číslo` IS NULL)";
    else Obj_cislo = "(`Objednací číslo` LIKE '%"+arg1+"%')";;
    Update_list();
}


void Prijem_novy_1::on_Vyr_cislo_2_textChanged(const QString &arg1)
{
    if(arg1 == "") Vyr_cislo = "(`Číslo výrobce` LIKE '%' OR `Číslo výrobce` IS NULL)";
    else Vyr_cislo = "(`Číslo výrobce` LIKE '%"+arg1+"%')";;
    Update_list();
}


void Prijem_novy_1::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    qDebug()<<ui->tableWidget->item(index.row(), 0)->text();

    QString Query = "SELECT Nazev.ID AS 'ID',\
            Nazev.Název AS 'Name',\
            EAN.EAN AS 'EAN',\
            OBJ_cislo.`Objednací číslo` AS 'obj_cislo',\
            VYR_cislo.`Číslo výrobce` AS 'vyr_cislo',\
            Vyrobce.Výrobce_W AS 'Vyrobce_W',\
            Vyrobce.Výrobce_S AS 'Vyrobce_S',\
            kategorie.`Kategorie` AS 'Kategorie'\
            FROM `Interni_ID` Nazev,\
            `EAN` EAN,\
            `Objednací číslo` OBJ_cislo,\
            `Číslo výrobce` VYR_cislo,\
            `Výrobce` Vyrobce,\
            `Prirazeni_kategorii` kategorie\
            WHERE Nazev.ID = "+ui->tableWidget->item(index.row(), 0)->text()+"\
            AND EAN.Interni_ID = "+ui->tableWidget->item(index.row(), 0)->text()+"\
            AND OBJ_cislo.Interni_ID = "+ui->tableWidget->item(index.row(), 0)->text()+"\
            AND VYR_cislo.Interni_ID = "+ui->tableWidget->item(index.row(), 0)->text()+"\
            AND Vyrobce.Interni_ID = "+ui->tableWidget->item(index.row(), 0)->text()+"\
            AND kategorie.Soucastka = "+ui->tableWidget->item(index.row(), 0)->text();

    QMap<QString, QStringList> data = network.getData(Query);

    ui->Nazev_2->setText(data["Name"][0]);
    ui->EAN_2->setText(data["EAN"][0]);
    ui->Obj_cislo_2->setText(data["obj_cislo"][0]);
    ui->Vyr_cislo_2->setText(data["vyr_cislo"][0]);

    if(data["Vyrobce_W"][0] != QString("")) ui->Kategorie_2->setText(data["Vyrobce_W"][0]);
    else if(data["Vyrobce_S"][0] != QString("")){
        QString Query = "SELECT `Název` AS 'Name' FROM `Výrobci` WHERE `ID` = "+data["Vyrobce_S"][0];
        QMap<QString, QStringList> producer = network.getData(Query);
        ui->Kategorie_2->setText(producer["Name"][0]);
    }
    else ui->Kategorie_2->setText(QString(""));

    ui->Nazev->setEnabled(0);
    ui->EAN->setEnabled(0);
    ui->Obj_cislo->setEnabled(0);
    ui->Vyr_cislo->setEnabled(0);
    ui->checkBox->setEnabled(0);
    Show_secondary_input();
}

    QString Query = "SELECT Nazev.ID AS 'ID',\
            Nazev.Název AS 'Name',\
            EAN.EAN AS 'EAN',\
            OBJ_cislo.`Objednací číslo` AS 'obj_cislo',\
            VYR_cislo.`Číslo výrobce` AS 'vyr_cislo',\
            Vyrobce.Výrobce_W AS 'Vyrobce_W',\
            Vyrobce.Výrobce_S AS 'Vyrobce_S',\
            kategorie.`Kategorie` AS 'Kategorie'\
            FROM `Interni_ID` Nazev,\
            `EAN` EAN,\
            `Objednací číslo` OBJ_cislo,\
            `Číslo výrobce` VYR_cislo,\
            `Výrobce` Vyrobce,\
            `Prirazeni_kategorii` kategorie\
            WHERE Nazev.ID = "+ui->tableWidget->item(index.row(), 0)->text()+"\
            AND EAN.Interni_ID = "+ui->tableWidget->item(index.row(), 0)->text()+"\
            AND OBJ_cislo.Interni_ID = "+ui->tableWidget->item(index.row(), 0)->text()+"\
            AND VYR_cislo.Interni_ID = "+ui->tableWidget->item(index.row(), 0)->text()+"\
            AND Vyrobce.Interni_ID = "+ui->tableWidget->item(index.row(), 0)->text()+"\
            AND kategorie.Soucastka = "+ui->tableWidget->item(index.row(), 0)->text();

    QMap<QString, QStringList> data = network.getData(Query);
    qDebug() << "Data for completion" << data;
    ui->Nazev_2->setText(data["Name"][0]);
    ui->EAN_2->setText(data["EAN"][0]);
    ui->Obj_cislo_2->setText(data["obj_cislo"][0]);
    ui->Vyr_cislo_2->setText(data["vyr_cislo"][0]);

    if(data["Vyrobce_W"][0] != QString("")) ui->Vyrobce_2->setText(data["Vyrobce_W"][0]);
    else if(data["Vyrobce_S"][0] != QString("")){
        QString Query = "SELECT `Název` AS 'Name' FROM `Výrobci` WHERE `ID` = "+data["Vyrobce_S"][0];
        QMap<QString, QStringList> producer = network.getData(Query);
        ui->Vyrobce_2->setText(producer["Name"][0]);
    }
    else ui->Vyrobce_2->setText(QString(""));

    Query = "SELECT `Nazev` AS 'Category_Name' FROM `Kategorie` WHERE `ID` = "+data["Kategorie"][0];
    QMap<QString, QStringList> Category_Name = network.getData(Query);
    ui->Kategorie_2->setText(Category_Name["Name"][0]);

    ui->Nazev->setEnabled(0);
    ui->EAN->setEnabled(0);
    ui->Obj_cislo->setEnabled(0);
    ui->Vyr_cislo->setEnabled(0);
    ui->New_Part->setEnabled(0);

    Show_secondary_input();
}

void Prijem_novy_1::Show_secondary_input()
{

    ui->tableWidget->hide();

    ////////////////////////////////////////// ZÍSKÁNÍ STAVŮ PRO AUTOMATICKÉ DOPLNĚNÍ
    QString Query = "SELECT `Název` AS 'Name' FROM `Stavy` WHERE 1";
    QMap<QString, QStringList> data = network.getData(Query);
    qDebug() << data["Name"];
    QCompleter *completer = new QCompleter(data["Name"], this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->Stav_2->setCompleter(completer);

    ui->tableWidget->setEnabled(0);

    ui->Umisteni->show();
    ui->Dodavatel->show();
    ui->Cena->show();
    ui->Stav->show();
    ui->Poznamka->show();
    ui->Polozek->show();

    /*
    /// https://stackoverflow.com/questions/6452077/how-to-get-click-event-of-qlineedit-in-qt
    /// Pro každý line edit (nyní combobox, který má v databázi předchystaný výběr
    /// Have fun Pěťo :D
    */

    if(ui->Stav_2->text().isEmpty())
    {
        ui->Stav_2->completer()->setCompletionPrefix("");
        ui->Stav_2->completer()->complete();
    }

    ///

}

void Prijem_novy_1::Hide_secondary_input()
{
    ui->tableWidget->setEnabled(1);

    ui->Umisteni->hide();
    ui->Dodavatel->hide();
    ui->Cena->hide();
    ui->Stav->hide();
    ui->Poznamka->hide();
    ui->Polozek->hide();
}

void Prijem_novy_1::Show_new_input()
{
    ui->Kategorie->setEnabled(1);
    ui->Vyrobce->setEnabled(1);
}

void Prijem_novy_1::Hide_new_input()
{
    ui->Kategorie->setEnabled(0);
    ui->Vyrobce->setEnabled(0);
}

void Prijem_novy_1::on_Kategorie_3_pressed()
{

    Category.show();

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
}


void Prijem_novy_1::on_pushButton_pressed()
{
    ui->New_Part->setChecked(true);
}


void Prijem_novy_1::on_New_Part_stateChanged(int arg1)
{
    qDebug()<<arg1;
    if(!arg1){
        Hide_secondary_input();
        Hide_new_input();
    }
    else{
        Show_secondary_input();
        Show_new_input();
    }
}


void Prijem_novy_1::on_Currency_currentTextChanged(const QString &arg1)
{
    if(arg1 != "Kč") ui->Date_exchange->show();
    else ui->Date_exchange->hide();

}


void Prijem_novy_1::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1 != "Kč") ui->Date_exchange->show();
    else ui->Date_exchange->hide();
}

void Prijem_novy_1::on_Stav_2_selectionChanged()
{
    qDebug() << "Nice";
    Show_secondary_input();
}

