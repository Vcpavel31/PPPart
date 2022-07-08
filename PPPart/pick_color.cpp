#include "pick_color.h"
#include "ui_pick_color.h"

Pick_Color::Pick_Color(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pick_Color)
{
    ui->setupUi(this);
}

Pick_Color::~Pick_Color()
{
    delete ui;
}
