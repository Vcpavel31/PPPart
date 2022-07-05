#include "input_element5.h"
#include "ui_input_element5.h"

Input_Element5::Input_Element5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Input_Element5)
{
    ui->setupUi(this);
}

Input_Element5::~Input_Element5()
{
    delete ui;
}
