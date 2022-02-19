#ifndef PRIJEM_NOVY_1_H
#define PRIJEM_NOVY_1_H

#include <QDialog>

namespace Ui {
class prijem_novy_1;
}

class prijem_novy_1 : public QDialog
{
    Q_OBJECT

public:
    explicit prijem_novy_1(QWidget *parent = nullptr);
    ~prijem_novy_1();

private:
    Ui::prijem_novy_1 *ui;
};

#endif // PRIJEM_NOVY_1_H
