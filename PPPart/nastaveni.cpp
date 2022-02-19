#include "nastaveni.h"
#include "ui_nastaveni.h"

Nastaveni::Nastaveni(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nastaveni)
{
    ui->setupUi(this);
}

Nastaveni::~Nastaveni()
{
    delete ui;
}
