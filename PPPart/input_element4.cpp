#include "input_element4.h"
#include "ui_input_element4.h"

Input_Element4::Input_Element4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Input_Element4)
{
    ui->setupUi(this);
}

Input_Element4::~Input_Element4()
{
    delete ui;
}
