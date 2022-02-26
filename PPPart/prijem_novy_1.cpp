#include "prijem_novy_1.h"
#include "ui_prijem_novy_1.h"



Prijem_novy_1::Prijem_novy_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Prijem_novy_1)
{
    ui->setupUi(this);

    ui->Umisteni->hide();
    ui->Kategorie->hide();
    ui->Dodavatel->hide();
    ui->Vyrobce->hide();
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
    ui->Kapacita->hide();
    ui->Jme_vykon->hide();
    ui->Jme_napeti->hide();
    ui->Ozn_knihovna->hide();
    ui->Baleni->hide();
    ui->Int_oznaceni->hide();

    Update_list();
}

Prijem_novy_1::~Prijem_novy_1()
{
    delete ui;
}

void Prijem_novy_1::Update_list()
{

    QString Query = "SELECT Nazev.ID,Nazev.Název,EAN.EAN FROM Interni_ID Nazev, EAN EAN WHERE Nazev.ID = EAN.Interni_ID AND Nazev.Název LIKE '"+Nazev+"' AND Nazev.ID IN (\
                SELECT `Interni_ID` FROM `Objednací číslo` WHERE "+Obj_cislo+" AND `Interni_ID` IN (\
                SELECT `Interni_ID` FROM `EAN` WHERE "+EAN+"  AND `Interni_ID` IN (\
                SELECT `Interni_ID` FROM `Číslo výrobce` WHERE "+Vyr_cislo+" ) ) )";


    QMap<QString, QStringList> data = network.getData(Query);
    qDebug() << "Data: " << data;
    ui->tableWidget->setRowCount(0);
    for(int i = 0; i != data["ID"].size(); i++)
    {
        QString EAN = network.getStringData("SELECT `EAN` FROM `EAN` WHERE `Interni_ID` = '"+data["ID"].at(i)+"'");
        qDebug() << "EAN: " << EAN;

        if(!data["ID"].at(i).isEmpty())
          {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(data["ID"].at(i)));
        }
        else
            {
                qDebug() << "ERROR: didnt receive ID";
                //TODO zobraz Nenalezeny součástky odpovídající kritériím
        }

        if(!data["Name"].at(i).isEmpty())
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(data["Name"].at(i)));
        else
            qDebug() << "ERROR: didnt receive Name";

        if(!EAN.isEmpty())
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(EAN));
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
    Show_secondary_input();
}


void Prijem_novy_1::on_checkBox_stateChanged(int arg1)
{
    qDebug()<<arg1;
    if(!arg1){
        Hide_secondary_input();
    }
    else{
        Show_secondary_input();
    }
}

void Prijem_novy_1::Show_secondary_input()
{
    ui->tableWidget->hide();

    ui->Umisteni->show();
    ui->Dodavatel->show();
    ui->Cena->show();
    ui->Stav->show();
    ui->Poznamka->show();
}

void Prijem_novy_1::Hide_secondary_input()
{
    ui->tableWidget->show();

    ui->Umisteni->hide();
    ui->Dodavatel->hide();
    ui->Cena->hide();
    ui->Stav->hide();
    ui->Poznamka->hide();
}
