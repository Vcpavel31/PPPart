#include "input_element6.h"
#include "ui_input_element6.h"

Input_Element6::Input_Element6(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Input_Element6)
{
    ui->setupUi(this);
}

Input_Element6::~Input_Element6()
{
    delete ui;
}
