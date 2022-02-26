#include "category.h"
#include "ui_category.h"

Category::Category(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Category)
{
    ui->setupUi(this);

    QString Query = "SELECT Kategorie.ID AS 'ID', Kategorie.Nazev AS 'Nazev', Usporadani.Nadrazena AS 'Nadrazena' FROM Kategorie Kategorie, Usporadani_kategorii Usporadani WHERE Kategorie.ID = Usporadani.Kategorie AND Usporadani.Uzivatel = '1'";

    QMap<QString, QStringList> data = network.getData(Query);
    qDebug() << "Data: " << data;
    ui->categories->setColumnHidden(1, 1);
    ui->categories->clear();
    for(int i = 0; i != data["ID"].size(); i++)
    {
        if(data["Nadrazena"][i].isEmpty()){
            ui->categories->insertTopLevelItem(ui->categories->topLevelItemCount(), new QTreeWidgetItem(QStringList({data["Nazev"][i], data["ID"][i]})));
        }
        else{
            QList<QTreeWidgetItem *> items = ui->categories->findItems(data["Nadrazena"][i], Qt::MatchExactly|Qt::MatchRecursive, 1);
            if(!items.isEmpty()) // parent item exists
                {
                //only one item with same ID => at(0)
                items.at(0)->addChild(new QTreeWidgetItem(QStringList({data["Nazev"][i], data["ID"][i]})));
                qDebug() << "Parent item exists: " << items.at(0)->text(0);
            }
        }
    }

}

Category::~Category()
{
    delete ui;
}
