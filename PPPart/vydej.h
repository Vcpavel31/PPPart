#ifndef VYDEJ_H
#define VYDEJ_H

#include <QDialog>

namespace Ui {
class Vydej;
}

class Vydej : public QDialog
{
    Q_OBJECT

public:
    explicit Vydej(QWidget *parent = nullptr);
    ~Vydej();

private:
    Ui::Vydej *ui;
};

#endif // VYDEJ_H
