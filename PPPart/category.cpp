#include "category.h"
#include "ui_category.h"

Category::Category(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Category)
{
    ui->setupUi(this);

    QMap<QString, QStringList> data = network.getData("MACRO(CategoryList)");
    qDebug() << "CategoryList: " << data;
    ui->categories->setColumnHidden(1, 1);
    ui->categories->clear();

    QList<QTreeWidgetItem*> items;
    for(int i = 0; i != data["ID"].size(); i++)
    {
        QTreeWidgetItem* item = new QTreeWidgetItem(QStringList({data["Name"][i], data["ID"][i]}));
        items.append(item);
    }
    ui->categories->insertTopLevelItems(0, items);

}

Category::~Category()
{
    delete ui;
}

void Category::on_buttonBox_accepted()
{

}


void Category::on_categories_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    (void) column; // dont care about column
    selectedItem = item;
    accept();
}

void Category::on_categories_itemClicked(QTreeWidgetItem *item, int column)
{
    (void) column; // dont care about column
    selectedItem = item;
}

QTreeWidgetItem Category::getSelectedItem()
{
    return *selectedItem;
}

void Category::on_categories_itemSelectionChanged() // just to be sure
{
    selectedItem = ui->categories->selectedItems().at(0);
}

