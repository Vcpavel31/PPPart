#include "vydej.h"
#include "ui_vydej.h"

Vydej::Vydej(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Vydej)
{
    ui->setupUi(this);
}

Vydej::~Vydej()
{
    delete ui;
}
