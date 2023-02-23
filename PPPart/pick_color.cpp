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


QColor Pick_Color::getIdealTextColor(const QColor rBackgroundColor){
    const int THRESHOLD = 105;
    const int BG_RED = rBackgroundColor.red();
    const int BG_GREEN = rBackgroundColor.green();
    const int BG_BLUE = rBackgroundColor.blue();
    int BackgroundDelta = ((BG_RED << 2) + BG_RED + (BG_GREEN << 1) + BG_GREEN + (BG_BLUE)) >> 3;
    return QColor((255 - BackgroundDelta < THRESHOLD) ? Qt::black : Qt::white);
}


void Pick_Color::on_buttonBox_accepted()
{
    accept();
}


// Nabízet často používané barvy pomocí : https://github.com/pothosware/PothosFlow/blob/master/qtcolorpicker/src/qtcolorpicker.cpp

void Pick_Color::refresh() {
    int red = 0;
    int green = 0;
    int blue = 0;
    int alpha = ui->Transparent->isChecked() ? 0 : 255;
    int j = 0;

    // Calculate the average color of selected color sources.
    for (const auto& color_source : {"RAL", "ColorDialog"}) {
        if (colors.contains(color_source) && findChild<QCheckBox*>(color_source)->isChecked()) {
            const auto& color = colors[color_source];
            red += color.red();
            green += color.green();
            blue += color.blue();
            alpha += color.alpha();
            j++;
        }
    }

    if (j == 0) j = 1;
    color = QColor(red / j, green / j, blue / j, alpha / j);

    const auto ideal_text_color = getIdealTextColor(color);
    const auto button_style = QString("QPushButton { background-color : %1; color : %2; }").arg(color.name()).arg(ideal_text_color.name());
    ui->pushButton_2->setStyleSheet(button_style);
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
    (void) arg1;

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

QColor Pick_Color::hexToRGB(const QString& hex) {
    bool bStatus = false;

    int r = hex.mid(1, 2).toInt(&bStatus, 16);
    int g = hex.mid(3, 2).toInt(&bStatus, 16);
    int b = hex.mid(5, 2).toInt(&bStatus, 16);

    return QColor(r, g ,b , ui->Transparent->checkState() != Qt::Unchecked ? 255 : 122);
}


void Pick_Color::on_RAL_stateChanged(int arg1){
    (void) arg1;
    refresh();
}


void Pick_Color::on_Pantone_stateChanged(int arg1){
    (void) arg1;
    refresh();
}


void Pick_Color::on_NCS_stateChanged(int arg1){
    (void) arg1;
    refresh();
}


void Pick_Color::on_Manual_stateChanged(int arg1){
    (void) arg1;
    refresh();
}


void Pick_Color::on_Transparent_stateChanged(int arg1){
    (void) arg1;
    refresh();
}

