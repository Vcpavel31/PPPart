#ifndef INPUT_ELEMENT1_H
#define INPUT_ELEMENT1_H

#include <QDialog>

namespace Ui {
class Input_Element1;
}

class Input_Element1 : public QDialog
{
    Q_OBJECT

public:
    explicit Input_Element1(QWidget *parent = nullptr);
    ~Input_Element1();

private:
    Ui::Input_Element1 *ui;
};

#endif // INPUT_ELEMENT1_H
