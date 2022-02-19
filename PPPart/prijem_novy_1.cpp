#include "prijem_novy_1.h"
#include "ui_prijem_novy_1.h"

Prijem_novy_1::Prijem_novy_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Prijem_novy_1)
{
    ui->setupUi(this);
}

Prijem_novy_1::~Prijem_novy_1()
{
    delete ui;
}
