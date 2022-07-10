#ifndef PICK_COLOR_H
#define PICK_COLOR_H

#include <QDialog>
#include <QColorDialog>

#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

namespace Ui {
class Pick_Color;
}

class Pick_Color : public QDialog
{
    Q_OBJECT

public:
    explicit Pick_Color(QWidget *parent = nullptr);
    ~Pick_Color();

    QColor getColor();

    QMap<QString, QColor> colors;

private:
    Ui::Pick_Color *ui;

    //const QString COLOR_STYLE = "QPushButton { background-color : %1; color : %2; }";

    QColor color;

private slots:
    QColor getIdealTextColor(const QColor rBackgroundColor);

    QColor hexToRGB(QString hex);

    void on_buttonBox_accepted();

    void refresh();

    void on_pushButton_clicked();

    void on_RAL_Value_textChanged(const QString &arg1);
    void on_RAL_stateChanged(int arg1);
    void on_Pantone_stateChanged(int arg1);
    void on_NCS_stateChanged(int arg1);
    void on_Manual_stateChanged(int arg1);
    void on_Transparent_stateChanged(int arg1);
};

#endif // PICK_COLOR_H
