#include "prijem_novy_1.h"
#include "ui_prijem_novy_1.h"

QString Nazev = "%";
QString EAN = "%";
QString Obj_cislo = "%";
QString Vyr_cislo = "%";

QString Response = "";

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

}

Prijem_novy_1::~Prijem_novy_1()
{
    delete ui;
}

void Prijem_novy_1::replyFinished (QNetworkReply *reply)
{
    qDebug() << reply->readAll();  // Narvat do Response nebo ideálně return to by mi vyhovovalo víc ale co už :D
}

QString Prijem_novy_1::DB (QString Query)
{
    QSettings *settings = new QSettings(QSettings::IniFormat, QSettings::UserScope, "PPPart");

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    QUrl url(settings->value("Address").toString());
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrlQuery params;
    params.addQueryItem("User", settings->value("User").toString());
    params.addQueryItem("Pass", settings->value("Pass").toString());
    params.addQueryItem("Debug", "False");
    params.addQueryItem("Query", Query);

    QObject::connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));

    //qDebug() <<
    params.query().toUtf8();
    //qDebug() <<
    manager->post(request, params.query().toUtf8())->error();
}

void Prijem_novy_1::Update_list()
{
    qDebug() << "Nazev: "+Nazev;

    qDebug() << DB("SELECT `Interni_ID` FROM `EAN` WHERE `EAN` LIKE '"+EAN+"'");
    DB("SELECT `Interni_ID` FROM `Objednací číslo` WHERE `Objednací číslo` LIKE '"+Obj_cislo+"'");
    DB("SELECT `Interni_ID` FROM `Číslo výrobce` WHERE `Číslo výrobce` LIKE '"+Vyr_cislo+"'");

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

