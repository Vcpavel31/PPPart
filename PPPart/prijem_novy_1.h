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
#include <QWidgetItem>

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

    QMap<QString, QWidget*> pointers;

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

    void currency_changed(const QString &text);

    void on_Stav_2_selectionChanged();

    void set_ComboBox(QMap<QString, QStringList> response, QMap<QString, QWidget*> pointers, int j);

    void set_Helper(QMap<QString, QStringList> response, int j);

    void create_input();

    void send_DB();

    QColor getIdealTextColor(const QColor rBackgroundColor);

    void ColorPick();

private:
    Ui::Prijem_novy_1 *ui;

    QString Nazev = "%";
    QString EAN = "(`EAN` LIKE '%' OR `EAN` IS NULL)";
    QString Obj_cislo = "";
    QString Vyr_cislo = "(`Product_number` LIKE '%' OR `Product_number` IS NULL)";
    QString Response = "";

    int rows = 6;

    QStringList array;
    QStringList Enabled_Categories;

    QMap<QString, int> Categories;

    NetworkSQL network;
    Category category;
    QColor color = QColor(255, 255, 255, 255);
    int categoryID = -1;

    void Update_list();

    QComboBox* ComboBox;
    QDateEdit* DateEdit;

};

#endif // PRIJEM_NOVY_1_H
