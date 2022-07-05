#ifndef INPUT_ELEMENT2_H
#define INPUT_ELEMENT2_H

#include <QDialog>

namespace Ui {
class Input_Element2;
}

class Input_Element2 : public QDialog
{
    Q_OBJECT

public:
    explicit Input_Element2(QWidget *parent = nullptr);
    ~Input_Element2();

private:
    Ui::Input_Element2 *ui;
};

#endif // INPUT_ELEMENT2_H
