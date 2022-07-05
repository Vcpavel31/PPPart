#include "input_element3.h"
#include "ui_input_element3.h"

Input_Element3::Input_Element3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Input_Element3)
{
    ui->setupUi(this);
}

Input_Element3::~Input_Element3()
{
    delete ui;
}
