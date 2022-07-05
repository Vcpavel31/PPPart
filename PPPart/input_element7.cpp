#include "input_element7.h"
#include "ui_input_element7.h"

Input_Element7::Input_Element7(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Input_Element7)
{
    ui->setupUi(this);
}

Input_Element7::~Input_Element7()
{
    delete ui;
}
