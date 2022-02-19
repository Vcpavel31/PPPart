#include "prijem_novy_2.h"
#include "ui_prijem_novy_2.h"

Prijem_novy_2::Prijem_novy_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Prijem_novy_2)
{
    ui->setupUi(this);
}

Prijem_novy_2::~Prijem_novy_2()
{
    delete ui;
}
