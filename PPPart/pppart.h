#ifndef PPPART_H
#define PPPART_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QInputDialog>
#include <QMessageBox>
#include <QSettings>
#include <QtNetwork/QSsl>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>
#include <QUrl>
#include <QUrlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class PPPart; }
QT_END_NAMESPACE

class PPPart : public QMainWindow
{
    Q_OBJECT

public:
    PPPart(QWidget *parent = nullptr);
    ~PPPart();

private slots:
    void replyFinished (QNetworkReply *reply);

    void on_treeWidget_2_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_pushButton_2_pressed();

private:
    Ui::PPPart *ui;

    QSettings *settings = new QSettings(QSettings::IniFormat, QSettings::UserScope, "PPPart");

    void itemsChanged();
};
#endif // PPPART_H
