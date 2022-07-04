#include "input_element2.h"
#include "ui_input_element2.h"

Input_Element2::Input_Element2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Input_Element2)
{
    ui->setupUi(this);
}

Input_Element2::~Input_Element2()
{
    delete ui;
}
