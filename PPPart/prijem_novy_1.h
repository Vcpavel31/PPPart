#ifndef PRIJEM_NOVY_1_H
#define PRIJEM_NOVY_1_H

#include <QDialog>

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

    void Update_list();

private:
    Ui::Prijem_novy_1 *ui;
};

#endif // PRIJEM_NOVY_1_H
