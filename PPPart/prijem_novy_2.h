#ifndef PRIJEM_NOVY_2_H
#define PRIJEM_NOVY_2_H

#include <QDialog>

namespace Ui {
class prijem_novy_2;
}

class prijem_novy_2 : public QDialog
{
    Q_OBJECT

public:
    explicit prijem_novy_2(QWidget *parent = nullptr);
    ~prijem_novy_2();

private:
    Ui::prijem_novy_2 *ui;
};

#endif // PRIJEM_NOVY_2_H
