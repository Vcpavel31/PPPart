#include "pppart.h"
#include "ui_pppart.h"

PPPart::PPPart(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PPPart)
{
    ui->setupUi(this);
    //settings->setDefaultFormat(QSettings::IniFormat);
    //qDebug() << settings->status() << " " << settings->fileName();

    getAllData();

    QString Query = "SELECT `Categories`.ID AS 'ID',\
                     `Categories`.`Name` AS 'Name',\
                     `Categories_Arrangement`.`Ordered` AS 'Ordered'\
                     FROM `Categories`, `Categories_Arrangement`\
                     WHERE `Categories`.ID = `Categories_Arrangement`.`Category` AND `Categories`.`Hidden` = '0'";
    QMap<QString, QStringList> data = network.getData(Query);
    ui->categories->setColumnHidden(1, 1);
    ui->categories->clear();
    for(int i = 0; i != data["ID"].size(); i++){
        if(data["Ordered"][i].isEmpty()){
            ui->categories->insertTopLevelItem(ui->categories->topLevelItemCount(), new QTreeWidgetItem(QStringList({data["Name"][i], data["ID"][i]})));
        }
        else{
            QList<QTreeWidgetItem *> items = ui->categories->findItems(data["Ordered"][i], Qt::MatchExactly|Qt::MatchRecursive, 1);
            if(!items.isEmpty()){ // parent item exists
                //only one item with same ID => at(0)
                items.at(0)->addChild(new QTreeWidgetItem(QStringList({data["Name"][i], data["ID"][i]})));
                qDebug() << "Parent item exists: " << items.at(0)->text(0);
            }
        }
    }
}

PPPart::~PPPart()
{
    delete ui;
}

void PPPart::getAllData()
{
}

void PPPart::on_categories_itemClicked(QTreeWidgetItem *item, int column)
{
    ui->parts->clear();
    qDebug() << "left bar" << item->text(1);

    //////////////////////////////////////////////////////////////////////////////////
    /// TODO: Z DB získat jaké sloupce u vybrané kategorie jsou a na ty připravit Treewidget
    /// TODO: Připravý z DB query pro další atributy které nejsou v halvní tabulce položek
    QString Query = ("SELECT `Attributes` FROM `Categories_Attributes` WHERE `Hidden` = 0 AND `Category` = "+item->text(1));
    qDebug() << Query;
    QMap<QString, QStringList> attributes = network.getData(Query);
    qDebug() << attributes;

    /////////////////////////////////////////////////////////////////////////////////
    /// \brief Data součástek
    /// Získání informací o jednotlivých položkách ve skladu odpovídajícím kategorii

    Query = ("SELECT `Item_ID` AS 'ID' FROM `Categories_Items` WHERE `Category_ID` = "+item->text(1));
    QMap<QString, QStringList> items = network.getData(Query);
    for(int i = 0; i != items["ID"].size(); i++){
        Query = ("SELECT `ID`,`Name`, `EAN`, `Product_number` FROM `Items` WHERE `ID` = "+items["ID"][i]);
        QMap<QString, QStringList> data = network.getData(Query);
        for(int j = 0; j != data["ID"].size(); j++){
            ui->parts->insertTopLevelItem(ui->parts->topLevelItemCount(), new QTreeWidgetItem(QStringList({data["ID"][j], data["EAN"][j], data["Name"][j], data["Product_number"][j]})));
        }
        
    }
    ui->parts->update();
    (void) item; // dont care
    (void) column; // dont care
}


void PPPart::on_settings_pressed()
{
    // ?????????????????????????????????????????????????????????????
    // network.getData("SELECT `Interni_ID`, `EAN` FROM `EAN` WHERE `EAN` LIKE '%12%'");
}

void PPPart::on_parts_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    (void) column; // dont care about column probably
    bool ok;

    if(!item->childCount()) //if havent any children
        {
            QString text = QInputDialog::getText(this, tr("Počet kusů"), item->text(0), QLineEdit::Normal, "1",  &ok);
            if (ok && !text.isEmpty()) // ok pressed?
                {
                    if(item->text(1).toInt() >= text.toInt()) //enought parts?
                        {
                            qDebug() << "Noice";
                    } else
                        {
                            QMessageBox msgBox;
                            msgBox.setText(tr("Nedostatečné množství na skladu. Opakujte akci."));
                            msgBox.exec();
                    }
            }
    }
}


void PPPart::on_income_pressed()
{
    income.show();
}

