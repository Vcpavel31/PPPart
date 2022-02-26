#ifndef CATEGORY_H
#define CATEGORY_H

#include <QDialog>

#include "networksql.h"


namespace Ui {
class Category;
}

class Category : public QDialog
{
    Q_OBJECT

public:
    explicit Category(QWidget *parent = nullptr);
    ~Category();

private:
    Ui::Category *ui;

    NetworkSQL network;
};

#endif // CATEGORY_H
