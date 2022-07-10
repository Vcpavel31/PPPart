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
    return color;
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
    accept();
}


// Nabízet často používané barvy pomocí : https://github.com/pothosware/PothosFlow/blob/master/qtcolorpicker/src/qtcolorpicker.cpp

void Pick_Color::refresh(QColor target){
    color = target;
    QColor IdealTextColor = getIdealTextColor(color);
    ui->pushButton_2->setStyleSheet("QPushButton { background-color : "+color.name()+"; color : "+IdealTextColor.name()+"; }");
    ui->pushButton_2->setText(color.name());
}

void Pick_Color::on_pushButton_clicked()
{
    QColor ColorDialog = QColorDialog::getColor(Qt::yellow, this );
    if( ColorDialog.isValid() ){
        refresh(ColorDialog);
    }
}

void Pick_Color::on_RAL_Value_textChanged(const QString &arg1)
{
    qDebug() << "RAL" << ui->RAL_Value->text();
    ui->RAL->setCheckState(Qt::Checked);
    QString RAL_Code = "RAL "+ui->RAL_Value->text().simplified().remove(" ").remove("R").remove("A").remove("L");
    qDebug() << RAL_Code;

    ////// RAL Import

    QFile inFile("F:/PPPart/Color_Tables/RAL.json");
    inFile.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray data = inFile.readAll();
    inFile.close();

    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    if (doc.isNull()) {
        qDebug() << "Parse failed";
    }
    QJsonObject rootObj = doc.object();
    QMap<QString,QString> RAL_List;
    QJsonArray ptsArray = rootObj.value("data").toArray();
    qDebug() << "There are " << ptsArray.size() << "sets of points in the json file";
    foreach(const QJsonValue & val, ptsArray){
        QString x=val.toObject().value("RAL").toString();
        QString y=val.toObject().value("HEX").toString();
        RAL_List[x] = y;
    }

    qDebug() << "Finished parsing, heres the data";
    //qDebug() << RAL_List;

    if(RAL_List[RAL_Code] != ""){
        qDebug() << RAL_List[RAL_Code];
        qDebug() << hexToRGB(RAL_List[RAL_Code]);
        refresh(hexToRGB(RAL_List[RAL_Code]));
    }
}

QColor Pick_Color::hexToRGB(QString hex) {
    bool bStatus = false;

    qDebug() << "HEX" << hex << "R" << hex.mid(1, 2) << "G" << hex.mid(3, 2) << "B" << hex.mid(5, 2);

    int r = hex.mid(1, 2).toInt(&bStatus, 16);
    int g = hex.mid(3, 2).toInt(&bStatus, 16);
    int b = hex.mid(5, 2).toInt(&bStatus, 16);

    qDebug() << "R" << r << "G" << g << "B" << b;

    if(ui->Transparent->checkState() != Qt::Unchecked){
        return QColor(r, g ,b , 255);
    }
    else{
        return QColor(r, g ,b , 122);
    }
}
