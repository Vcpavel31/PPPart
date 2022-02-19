#include "prijem_novy_2.h"
#include "ui_prijem_novy_2.h"

prijem_novy_2::prijem_novy_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::prijem_novy_2)
{
    ui->setupUi(this);
}

prijem_novy_2::~prijem_novy_2()
{
    delete ui;
}
