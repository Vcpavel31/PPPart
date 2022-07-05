#ifndef INPUT_ELEMENT3_H
#define INPUT_ELEMENT3_H

#include <QDialog>

namespace Ui {
class Input_Element3;
}

class Input_Element3 : public QDialog
{
    Q_OBJECT

public:
    explicit Input_Element3(QWidget *parent = nullptr);
    ~Input_Element3();

private:
    Ui::Input_Element3 *ui;
};

#endif // INPUT_ELEMENT3_H
