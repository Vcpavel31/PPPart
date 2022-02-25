#include "networksql.h"

NetworkSQL::NetworkSQL(QObject *parent)
    : QObject{parent}
{

}

//TODO bug fix when enter more unknown component in to name
QMap<QString, QStringList> NetworkSQL::getData(QString Query)
{
    QMap<QString, QStringList> temp;

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
    QNetworkReply* reply = manager->post(request, params.query().toUtf8());

    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    //data received

    QByteArray data = reply->readAll();
    qDebug() << "all: " << data;
    if(!data.contains("[")) // bad reply?
        {
            qDebug() << "Something wrong?";
            return temp; // any data recieved
    }

    QStringList indexes;
    QStringList values;

    while(data.contains("["))
        {
        indexes << QString::fromUtf8(data.sliced(data.indexOf("[")+1, data.indexOf("]")-data.indexOf("[")-1).toStdString()); // returns Interni_ID, EAN, etc
        data.remove(0, data.indexOf("=>")+2);
        values << QString::fromUtf8(data.sliced(0, data.indexOf("\n"))).replace(" ", ""); // return value without whitespaces
    }

    for(int i=0;i<indexes.count();i++)
    {
        if(indexes[0] != indexes[i]) // all indexes are not the same, save to array
            {
            qDebug() << "Multiple indexes";
            for(int i=0;i<indexes.count();i++)
            {
                    temp[indexes[i]] << values[i];
            }
            qDebug() << temp;
            return temp;
        }

    }

    //not all indexes are the same

    temp[indexes[0]] = values;
    qDebug() << "Same indexes\n";
    qDebug() << temp;
    return temp;
}


