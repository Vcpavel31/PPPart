#include "pppart.h"
#include "ui_pppart.h"

PPPart::PPPart(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PPPart)
{
    ui->setupUi(this);
    //settings->setDefaultFormat(QSettings::IniFormat);
    qDebug() << settings->status() << " " << settings->fileName();

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
    params.addQueryItem("Query", "SELECT * FROM `Kategorie` WHERE 1");

    QObject::connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));

    qDebug() << params.query().toUtf8();
    qDebug() << manager->post(request, params.query().toUtf8())->error();
}

void PPPart::replyFinished (QNetworkReply *reply)
{
    qDebug() << reply->readAll();
    /*if(reply->error())
    {
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();
    }
    else
    {
        qDebug() << reply->header(QNetworkRequest::ContentTypeHeader).toString();
        qDebug() << reply->header(QNetworkRequest::LastModifiedHeader).toDateTime().toString();;
        qDebug() << reply->header(QNetworkRequest::ContentLengthHeader).toULongLong();
        qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();

        QFile *file = new QFile("C:/Qt/Dummy/downloaded.txt");
        if(file->open(QFile::Append))
        {
            file->write(reply->readAll());
            file->flush();
            file->close();
        }
        delete file;
    }

    reply->deleteLater();*/
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

