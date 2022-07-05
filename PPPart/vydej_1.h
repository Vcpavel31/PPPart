#ifndef VYDEJ_1_H
#define VYDEJ_1_H

#include <QDialog>
#include <QSpinBox>
namespace Ui {
class Vydej_1;
}

class Vydej_1 : public QDialog
{
    Q_OBJECT

public:
    explicit Vydej_1(QWidget *parent = nullptr);
    ~Vydej_1();

private:
    Ui::Vydej_1 *ui;
};

#endif // VYDEJ_1_H
