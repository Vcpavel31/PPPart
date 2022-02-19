#include "vydej_1.h"
#include "ui_vydej_1.h"

Vydej_1::Vydej_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Vydej_1)
{
    ui->setupUi(this);
}

Vydej_1::~Vydej_1()
{
    delete ui;
}
