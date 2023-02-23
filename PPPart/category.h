#ifndef CATEGORY_H
#define CATEGORY_H

#include <QDialog>
#include <QTreeWidget>

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
    QTreeWidgetItem getSelectedItem();

private slots:
    void on_buttonBox_accepted();

    void on_categories_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_categories_itemClicked(QTreeWidgetItem *item, int column);

    void on_categories_itemSelectionChanged();

private:
    Ui::Category *ui;

    NetworkSQL network;

    QTreeWidgetItem *selectedItem = new QTreeWidgetItem; // Inicialized, if anything selected
};

#endif // CATEGORY_H
