#ifndef INPUT_ELEMENT5_H
#define INPUT_ELEMENT5_H

#include <QDialog>

namespace Ui {
class Input_Element5;
}

class Input_Element5 : public QDialog
{
    Q_OBJECT

public:
    explicit Input_Element5(QWidget *parent = nullptr);
    ~Input_Element5();

private:
    Ui::Input_Element5 *ui;
};

#endif // INPUT_ELEMENT5_H
