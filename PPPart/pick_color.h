#ifndef PICK_COLOR_H
#define PICK_COLOR_H

#include <QDialog>

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

private:
    Ui::Pick_Color *ui;

private slots:
    QColor getIdealTextColor(const QColor rBackgroundColor);

    void on_buttonBox_accepted();
};

#endif // PICK_COLOR_H
