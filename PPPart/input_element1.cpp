#include "input_element1.h"
#include "ui_input_element1.h"

Input_Element1::Input_Element1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Input_Element1)
{
    ui->setupUi(this);
}

Input_Element1::~Input_Element1()
{
    delete ui;
}
