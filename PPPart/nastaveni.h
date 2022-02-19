#ifndef NASTAVENI_H
#define NASTAVENI_H

#include <QDialog>

namespace Ui {
class Nastaveni;
}

class Nastaveni : public QDialog
{
    Q_OBJECT

public:
    explicit Nastaveni(QWidget *parent = nullptr);
    ~Nastaveni();

private:
    Ui::Nastaveni *ui;
};

#endif // NASTAVENI_H
