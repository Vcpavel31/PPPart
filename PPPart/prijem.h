#ifndef PRIJEM_H
#define PRIJEM_H

#include <QDialog>

namespace Ui {
class prijem;
}

class prijem : public QDialog
{
    Q_OBJECT

public:
    explicit prijem(QWidget *parent = nullptr);
    ~prijem();

private:
    Ui::prijem *ui;
};

#endif // PRIJEM_H
