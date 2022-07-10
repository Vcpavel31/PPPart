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

QColor Pick_Color::getColor(){
    return QColor(0,0,0,255);
}

//==============================================================================
//  Nom : getIdealTextColor
//! @return an ideal label color, based on the given background color.
//! Based on http://www.codeproject.com/cs/media/IdealTextColor.asp
//==============================================================================
QColor Pick_Color::getIdealTextColor(const QColor rBackgroundColor){
    const int THRESHOLD = 105;
    int BackgroundDelta = (rBackgroundColor.red() * 0.299) + (rBackgroundColor.green() * 0.587) + (rBackgroundColor.blue() * 0.114);
    return QColor((255- BackgroundDelta < THRESHOLD) ? Qt::black : Qt::white);
}

void Pick_Color::on_buttonBox_accepted()
{
    qDebug() << "Kanti";
}

