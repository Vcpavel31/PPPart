#ifndef INPUT_ELEMENT7_H
#define INPUT_ELEMENT7_H

#include <QDialog>

namespace Ui {
class Input_Element7;
}

class Input_Element7 : public QDialog
{
    Q_OBJECT

public:
    explicit Input_Element7(QWidget *parent = nullptr);
    ~Input_Element7();

private:
    Ui::Input_Element7 *ui;
};

#endif // INPUT_ELEMENT7_H
