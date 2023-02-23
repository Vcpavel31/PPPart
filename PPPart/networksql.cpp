#include "networksql.h"

NetworkSQL::NetworkSQL(QObject *parent)
    : QObject{parent}
{
    //settings->setValue("User_ID", 1);
    Address = settings->value("Address").toString();
    User = settings->value("User").toString();
    Pass = settings->value("Pass").toString();
    User_ID = settings->value("User_ID").toString();
    //qDebug() << settings->fileName() << " " << Address << " " << User << " " << Pass << " " << User_ID;
}

QNetworkReply::NetworkError NetworkSQL::pushData(const QString& query)
{
    QUrl url(Address);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrlQuery params;
    params.addQueryItem("User", User);
    params.addQueryItem("Pass", Pass);
    params.addQueryItem("Debug", "False");
    params.addQueryItem("Query", query);

    QByteArray postData = params.query(QUrl::FullyEncoded).toUtf8();

    QNetworkReply* reply = manager->post(request, postData);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    return reply->error();
}


QMap<QString, QStringList> NetworkSQL::getData(QString Query)
{
    // Construct the request
    QUrl url(Address);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrlQuery params;
    params.addQueryItem("User", User);
    params.addQueryItem("Pass", Pass);
    params.addQueryItem("Debug", "True");
    params.addQueryItem("Query", Query.replace("+", "%2B").replace("-", "%2D"));

    QByteArray postData = params.query(QUrl::FullyEncoded).toUtf8();

    // Send the request and wait for the reply
    QNetworkReply* reply = manager->post(request, postData);
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // Parse the data received
    QMap<QString, QStringList> result;
    QByteArray data = reply->readAll();
    //qDebug() << "Received: " << data;
    if(!data.contains("[")) {
        qWarning() << "getData: Bad reply: " << data;
        return result;
    }

    QRegularExpression space("^\\s+|\\s+$");
    while(data.contains("[")) {
        QString index = QString::fromUtf8(data.sliced(data.indexOf("[")+1, data.indexOf("]")-data.indexOf("[")-1).toStdString());
        data.remove(0, data.indexOf("=>")+2);
        QString value = QString::fromUtf8(data.sliced(0, data.indexOf("\n"))).replace(space, "");
        result[index] << value;
    }
/*
    if(result.count() > 1) {
        qWarning() << "getData: Multiple indexes: " << result.keys();
    }
*/
    return result;
}

QString NetworkSQL::getStringData(const QString& Query)
{
    QUrl url(Address);
    url.setUserName(User);
    url.setPassword(Pass);

    QUrlQuery params;
    params.addQueryItem("Debug", "False");
    params.addQueryItem("Query", Query);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QNetworkReply* reply = manager->post(request, params.query().toUtf8());
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QByteArray data = reply->readAll();
    //qDebug() << "all: " << data;

    if (!data.contains('[')) {
        qDebug() << "Something wrong?";
        return QString();
    }

    QStringList indexes;
    QStringList values;
    while (data.contains('[')) {
        const auto startIndex = data.indexOf('[') + 1;
        const auto endIndex = data.indexOf(']');
        const auto indexLength = endIndex - startIndex;
        const auto index = QString::fromUtf8(data.mid(startIndex, indexLength));
        indexes << index;
        const auto valueStartIndex = data.indexOf("=>", endIndex) + 2;
        const auto valueEndIndex = data.indexOf('\n', valueStartIndex);
        const auto value = QString::fromUtf8(data.mid(valueStartIndex, valueEndIndex - valueStartIndex).trimmed());
        values << value;
        data = data.mid(valueEndIndex + 1);
    }

    if (indexes.count() != values.count()) {
        //qDebug() << "Indexes and values count mismatch";
        return QString();
    }

    QSet<QString> uniqueIndexes(indexes.begin(), indexes.end());
    if (uniqueIndexes.count() > 1) {
        //qDebug() << "Multiple indexes - badly used function";
        return QString();
    }

    return values.first();

}
