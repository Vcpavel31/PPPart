#include "prijem_novy_1.h"
#include "ui_prijem_novy_1.h"



Prijem_novy_1::Prijem_novy_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Prijem_novy_1)
{
    ui->setupUi(this);

    QObject::connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));

    qDebug() << settings->status() << " " << settings->fileName();

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

}

Prijem_novy_1::~Prijem_novy_1()
{
    delete ui;
}

void Prijem_novy_1::replyFinished (QNetworkReply *reply)
{
    QByteArray data = reply->readAll();  // Narvat do Response

    if(!data.contains("[")) // bad reply?
        qDebug() << "Something wrong?";

    while(data.contains("["))
        {
        data.remove(0, data.indexOf("[")+1);
        QString index = QString::fromUtf8(data.sliced(data.indexOf("]")).toStdString()); // returns Interni_ID, EAN, etc
        data.remove(0, data.indexOf("=>")+2);
        qDebug() << data << " index: " << index;
    }


    qDebug() << data;
}



void Prijem_novy_1::DB (QString Query)
{
    QUrl url(settings->value("Address").toString());
    qDebug() << url;
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrlQuery params;
    params.addQueryItem("User", settings->value("User").toString());
    params.addQueryItem("Pass", settings->value("Pass").toString());
    params.addQueryItem("Debug", "False");
    params.addQueryItem("Query", Query);

    qDebug() << 1;
    //qDebug() << params.query().toUtf8();
    qDebug() << "Return: " << manager->post(request, params.query().toUtf8())->rawHeaderList();
}

void Prijem_novy_1::Update_list()
{
    qDebug() << "Nazev: "+Nazev;

    //
    DB("SELECT `Interni_ID`, `EAN` FROM `EAN` WHERE `EAN` LIKE '"+EAN+"'");
    //DB("SELECT `Interni_ID` FROM `EAN` WHERE `EAN` LIKE '"+EAN+"'");
    /*DB("SELECT `Interni_ID` FROM `Objednací číslo` WHERE `Objednací číslo` LIKE '"+Obj_cislo+"'");
    DB("SELECT `Interni_ID` FROM `Číslo výrobce` WHERE `Číslo výrobce` LIKE '"+Vyr_cislo+"'");*/

    qDebug() << Response;
}

void Prijem_novy_1::on_Nazev_2_textChanged(const QString &arg1)
{
    if(arg1 == "") Nazev = "%";
    else Nazev = "%"+arg1+"%";
    Update_list();
}


void Prijem_novy_1::on_EAN_2_textChanged(const QString &arg1)
{
    if(arg1 == "") EAN = "%";
    else EAN = "%"+arg1+"%";
    Update_list();
}


void Prijem_novy_1::on_Obj_cislo_2_textChanged(const QString &arg1)
{
    if(arg1 == "") Obj_cislo = "%";
    else Obj_cislo = "%"+arg1+"%";
    Update_list();
}


void Prijem_novy_1::on_Vyr_cislo_2_textChanged(const QString &arg1)
{
    if(arg1 == "") Vyr_cislo = "%";
    else Vyr_cislo = "%"+arg1+"%";
    Update_list();
}

