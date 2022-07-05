#ifndef INPUT_ELEMENT6_H
#define INPUT_ELEMENT6_H

#include <QDialog>

namespace Ui {
class Input_Element6;
}

class Input_Element6 : public QDialog
{
    Q_OBJECT

public:
    explicit Input_Element6(QWidget *parent = nullptr);
    ~Input_Element6();

private:
    Ui::Input_Element6 *ui;
};

#endif // INPUT_ELEMENT6_H
