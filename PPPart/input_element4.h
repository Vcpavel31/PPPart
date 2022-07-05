#ifndef INPUT_ELEMENT4_H
#define INPUT_ELEMENT4_H

#include <QDialog>

namespace Ui {
class Input_Element4;
}

class Input_Element4 : public QDialog
{
    Q_OBJECT

public:
    explicit Input_Element4(QWidget *parent = nullptr);
    ~Input_Element4();

private:
    Ui::Input_Element4 *ui;
};

#endif // INPUT_ELEMENT4_H
