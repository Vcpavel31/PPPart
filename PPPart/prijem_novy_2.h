#ifndef PRIJEM_NOVY_2_H
#define PRIJEM_NOVY_2_H

#include <QDialog>

namespace Ui {
class Prijem_novy_2;
}

class Prijem_novy_2 : public QDialog
{
    Q_OBJECT

public:
    explicit Prijem_novy_2(QWidget *parent = nullptr);
    ~Prijem_novy_2();

private:
    Ui::Prijem_novy_2 *ui;
};

#endif // PRIJEM_NOVY_2_H
