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
#include <QCompleter>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPlainTextEdit>
#include <QComboBox>
#include <QDateEdit>

#include "networksql.h"
#include "category.h"

namespace Ui {
class Prijem_novy_1;
}

class Prijem_novy_1 : public QDialog
{
    Q_OBJECT

public:
    explicit Prijem_novy_1(QWidget *parent = nullptr);
    ~Prijem_novy_1();


private slots:
    void on_Nazev_2_textChanged(const QString &arg1);

    void on_EAN_2_textChanged(const QString &arg1);

    void on_Obj_cislo_2_textChanged(const QString &arg1);

    void on_Vyr_cislo_2_textChanged(const QString &arg1);

    void on_tableWidget_doubleClicked(const QModelIndex &index);

    void on_Kategorie_3_pressed();

    void on_Kategorie_2_textChanged(const QString &arg1);

    void on_pushButton_pressed();

    void on_New_Part_stateChanged(int arg1);

    void on_Currency_currentTextChanged(const QString &arg1);

    void on_Stav_2_selectionChanged();

private:
    Ui::Prijem_novy_1 *ui;

    QString Nazev = "%";
    QString EAN = "(`EAN` LIKE '%' OR `EAN` IS NULL)";
    QString Obj_cislo = "";
    QString Vyr_cislo = "(`Product_number` LIKE '%' OR `Product_number` IS NULL)";
    QString Response = "";

    QStringList array;
    QStringList Enabled_Categories;

    NetworkSQL network;
    Category category;

    QString categoryID;

    void Update_list();

};

#endif // PRIJEM_NOVY_1_H
