#ifndef PRIJEM_NOVY_1_H
#define PRIJEM_NOVY_1_H

#include <QDialog>

#include <QSettings>
#include <QtNetwork/QSsl>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>
#include <QUrl>
#include <QUrlQuery>

namespace Ui {
class Prijem_novy_1;
}

class Prijem_novy_1 : public QDialog
{
    Q_OBJECT

public:
    explicit Prijem_novy_1(QWidget *parent = nullptr);
    ~Prijem_novy_1();

public slots:
    void replyFinished (QNetworkReply *reply);

    void DB (QString Query);

private slots:
    void on_Nazev_2_textChanged(const QString &arg1);

    void on_EAN_2_textChanged(const QString &arg1);

    void on_Obj_cislo_2_textChanged(const QString &arg1);

    void on_Vyr_cislo_2_textChanged(const QString &arg1);


private:
    Ui::Prijem_novy_1 *ui;

    QString Nazev = "%";
    QString EAN = "%";
    QString Obj_cislo = "%";
    QString Vyr_cislo = "%";
    QString Response = "";

    QSettings *settings = new QSettings(QSettings::IniFormat, QSettings::UserScope, "PPPart");
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    QStringList array;

    void Update_list();
};

#endif // PRIJEM_NOVY_1_H
