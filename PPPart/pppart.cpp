#include "pppart.h"
#include "ui_pppart.h"

PPPart::PPPart(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PPPart)
{
    ui->setupUi(this);
}

PPPart::~PPPart()
{
    delete ui;
}


void PPPart::on_treeWidget_2_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    (void) column; // dont care about column probably
    bool ok;
    if(!item->takeChild(0)) //if havent any children
        {
            QString text = QInputDialog::getText(this, tr("Počet kusů"),
                                                    item->text(0), QLineEdit::Normal, "1",  &ok);

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


void PPPart::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    qDebug() << "left bar";
}

