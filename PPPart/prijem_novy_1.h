#ifndef PRIJEM_NOVY_1_H
#define PRIJEM_NOVY_1_H

#include <QDialog>

namespace Ui {
class Prijem_novy_1;
}

class Prijem_novy_1 : public QDialog
{
    Q_OBJECT

public:
    explicit Prijem_novy_1(QWidget *parent = nullptr);
    ~Prijem_novy_1();

private:
    Ui::Prijem_novy_1 *ui;
};

#endif // PRIJEM_NOVY_1_H
