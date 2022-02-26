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

    QString Query = "SELECT Kategorie.ID AS 'ID', Kategorie.Nazev AS 'Nazev', Usporadani.Nadrazena AS 'Nadrazena' FROM Kategorie Kategorie, Usporadani_kategorii Usporadani WHERE Kategorie.ID = Usporadani.Kategorie AND Usporadani.Uzivatel = '1'";

    QMap<QString, QStringList> data = network.getData(Query);
    qDebug() << "Data: " << data;
    ui->categories->setColumnHidden(1, 1);
    ui->categories->clear();
    for(int i = 0; i != data["ID"].size(); i++)
    {
        if(data["Nadrazena"][i] == QString("")){
            ui->categories->insertTopLevelItem(ui->categories->topLevelItemCount(), new QTreeWidgetItem((QTreeWidget*)0, QStringList({data["Nazev"][i], data["ID"][i]})));
        }
        else{
            ui->categories->itemAt(data["Nadrazena"][i].toInt(), data["Nadrazena"][i].toInt())->addChild(new QTreeWidgetItem((QTreeWidget*)0, QStringList({data["Nazev"][i], data["ID"][i]})));
        }
        //ui->categories->itemAt(ui->categories->topLevelItemCount(), ui->categories->topLevelItemCount())->addChild(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("%1").arg(i))));
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
    qDebug() << "left bar";
}


void PPPart::on_settings_pressed()
{
    network.getData("SELECT `Interni_ID`, `EAN` FROM `EAN` WHERE `EAN` LIKE '%12%'");
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

