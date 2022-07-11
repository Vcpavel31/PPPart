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

void Pick_Color::refresh(){
// Předělat na pointery ????
    QList keys = colors.keys();

    int red = 0;
    int green = 0;
    int blue = 0;
    int alpha;

    // Set the Alpha channel according to whether the transparency option in the UI is checked.

    if(ui->Transparent->checkState() == Qt::Unchecked) alpha = 0;
    else alpha = 255;

    int j = 0;
/*    for(int i = 0; i!= keys.size(); i++){
        red += colors[keys[i]].red();
        green += colors[keys[i]].green();
        blue += colors[keys[i]].blue();
        alpha += colors[keys[i]].alpha();
        j++;
    }*/

    if(colors["RAL"] != "" && ui->RAL->isChecked()){
        red += colors["RAL"].red();
        green += colors["RAL"].green();
        blue += colors["RAL"].blue();
        alpha += 255;
        j++;
    }
    if(colors["ColorDialog"] != "" && ui->Manual->isChecked()){
        red += colors["ColorDialog"].red();
        green += colors["ColorDialog"].green();
        blue += colors["ColorDialog"].blue();
        alpha += colors["ColorDialog"].alpha();
        j++;
    }

    if(j == 0) j = 1;
    qDebug() << "Averaging color with: " << j << "values. R: " << red << " G: " << green << " B: " << blue << " A: " << alpha;

    color = QColor(red/j, green/j, blue/j, alpha/j);

    QColor IdealTextColor = getIdealTextColor(color);
    //qDebug() << "QPushButton { background-color : "+color.name()+"; color : "+IdealTextColor.name()+"; }";
    ui->pushButton_2->setStyleSheet("QPushButton { background-color : "+color.name()+"; color : "+IdealTextColor.name()+"; }");

    ui->pushButton_2->setText(color.name());
}

void Pick_Color::on_pushButton_clicked(){
    ui->Manual->setCheckState(Qt::Checked);
    QColorDialog WindowColorDialog = QColorDialog(colors["ColorDialog"], this );
    WindowColorDialog.setOption(QColorDialog::ShowAlphaChannel);
    WindowColorDialog.setOption(QColorDialog::DontUseNativeDialog);
    QColor ColorDialog = WindowColorDialog.getColor();
    if( ColorDialog.isValid() ){
        colors["ColorDialog"] = ColorDialog;
        refresh();
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
    //qDebug() << "There are " << ptsArray.size() << "sets of points in the json file";
    foreach(const QJsonValue & val, ptsArray){
        QString x=val.toObject().value("RAL").toString();
        QString y=val.toObject().value("HEX").toString();
        RAL_List[x] = y;
    }

    qDebug() << "Finished parsing, heres the data";
    //qDebug() << RAL_List;

    if(RAL_List[RAL_Code] != ""){
        //qDebug() << RAL_List[RAL_Code];
        //qDebug() << hexToRGB(RAL_List[RAL_Code]);
        colors["RAL"] = hexToRGB(RAL_List[RAL_Code]);
        refresh();
    }
}

QColor Pick_Color::hexToRGB(QString hex) {
    bool bStatus = false;

    //qDebug() << "HEX" << hex << "R" << hex.mid(1, 2) << "G" << hex.mid(3, 2) << "B" << hex.mid(5, 2);

    int r = hex.mid(1, 2).toInt(&bStatus, 16);
    int g = hex.mid(3, 2).toInt(&bStatus, 16);
    int b = hex.mid(5, 2).toInt(&bStatus, 16);

    //qDebug() << "R" << r << "G" << g << "B" << b;

    if(ui->Transparent->checkState() != Qt::Unchecked){
        return QColor(r, g ,b , 255);
    }
    else{
        return QColor(r, g ,b , 122);
    }
}

void Pick_Color::on_RAL_stateChanged(int arg1)
{
    refresh();
}


void Pick_Color::on_Pantone_stateChanged(int arg1)
{
    refresh();
}


void Pick_Color::on_NCS_stateChanged(int arg1)
{
    refresh();
}


void Pick_Color::on_Manual_stateChanged(int arg1)
{
    refresh();
}


void Pick_Color::on_Transparent_stateChanged(int arg1)
{
    refresh();
}

