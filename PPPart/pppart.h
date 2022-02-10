#ifndef PPPART_H
#define PPPART_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QInputDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class PPPart; }
QT_END_NAMESPACE

class PPPart : public QMainWindow
{
    Q_OBJECT

public:
    PPPart(QWidget *parent = nullptr);
    ~PPPart();

private slots:
    void on_treeWidget_2_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::PPPart *ui;


};
#endif // PPPART_H
