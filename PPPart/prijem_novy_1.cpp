#include "prijem_novy_1.h"
#include "ui_prijem_novy_1.h"

prijem_novy_1::prijem_novy_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::prijem_novy_1)
{
    ui->setupUi(this);
}

prijem_novy_1::~prijem_novy_1()
{
    delete ui;
}
