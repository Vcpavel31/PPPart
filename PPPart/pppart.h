#ifndef PPPART_H
#define PPPART_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QInputDialog>
#include <QMessageBox>
#include <QLineSeries>

#include "prijem_novy_1.h"
#include "networksql.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PPPart; }
QT_END_NAMESPACE

class PPPart : public QMainWindow
{
    Q_OBJECT

public:
    PPPart(QWidget *parent = nullptr);
    ~PPPart();

public slots:
    void on_categories_itemClicked(QTreeWidgetItem *item, int column);

    void on_settings_pressed();

    void on_parts_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_income_pressed();

private slots:
    void on_parts_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::PPPart *ui;

    Prijem_novy_1 income;

    NetworkSQL network;

    QStringList hodnoty;

    QLineSeries *series;

    void getAllData();
};
#endif // PPPART_H
