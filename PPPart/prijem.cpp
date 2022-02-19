#include "prijem.h"
#include "ui_prijem.h"

prijem::prijem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::prijem)
{
    ui->setupUi(this);
}

prijem::~prijem()
{
    delete ui;
}
