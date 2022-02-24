#include "pppart.h"
#include "ui_pppart.h"

PPPart::PPPart(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PPPart)
{
    ui->setupUi(this);
    //settings->setDefaultFormat(QSettings::IniFormat);
    //qDebug() << settings->status() << " " << settings->fileName();

    itemsChanged();
}

PPPart::~PPPart()
{
    delete ui;
}

void PPPart::itemsChanged()
{
    //ui->treeWidget_2->setColumnHidden()
}

void PPPart::on_categories_itemClicked(QTreeWidgetItem *item, int column)
{
    qDebug() << "left bar";
}


void PPPart::on_settings_pressed()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    QUrl url(settings->value("Address").toString());
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrlQuery params;
    params.addQueryItem("User", settings->value("User").toString());
    params.addQueryItem("Pass", settings->value("Pass").toString());
    params.addQueryItem("Query", "SELECT `Interni_ID`, `EAN` FROM `EAN` WHERE `EAN` LIKE '%12%'");

    QObject::connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));

    qDebug() << params.query().toUtf8();
    qDebug() << manager->post(request, params.query().toUtf8())->error();
}

void PPPart::replyFinished (QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    qDebug() << "all: " << data;
    if(!data.contains("[")) // bad reply?
        qDebug() << "Something wrong?";

    QStringList indexes;
    QStringList values;

    while(data.contains("["))
        {
        indexes << QString::fromUtf8(data.sliced(data.indexOf("[")+1, data.indexOf("]")-data.indexOf("[")-1).toStdString()); // returns Interni_ID, EAN, etc
        data.remove(0, data.indexOf("=>")+2);
        values << QString::fromUtf8(data.sliced(0, data.indexOf("\n"))).replace(" ", ""); // return value without whitespaces
        qDebug() << data;
    }

    for(int i=0;i<indexes.count();i++)
    {
        if(indexes[0] != indexes[i]) // all indexes are the same, save to array
            ;
    }

    qDebug() << indexes << " " << values;
}


void PPPart::on_parts_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    (void) column; // dont care about column probably
    bool ok;

    if(!item->childCount()) //if havent any children
        {
            QString text = QInputDialog::getText(this, tr("Počet kusů"), item->text(0), QLineEdit::Normal, "1",  &ok);
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

