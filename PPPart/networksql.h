#ifndef NETWORKSQL_H
#define NETWORKSQL_H

#include <QObject>
#include <QSettings>
#include <QtNetwork/QSsl>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>
#include <QUrl>
#include <QUrlQuery>
#include <QMap>
#include <QEventLoop>

class NetworkSQL : public QObject
{
    Q_OBJECT
public:
    explicit NetworkSQL(QObject *parent = nullptr);
    QMap<QString, QStringList> getData(QString);

signals:

private:
    QSettings *settings = new QSettings(QSettings::IniFormat, QSettings::UserScope, "PPPart");
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
};

#endif // NETWORKSQL_H