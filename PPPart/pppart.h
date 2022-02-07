#ifndef PPPART_H
#define PPPART_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class PPPart; }
QT_END_NAMESPACE

class PPPart : public QMainWindow
{
    Q_OBJECT

public:
    PPPart(QWidget *parent = nullptr);
    ~PPPart();

private:
    Ui::PPPart *ui;
};
#endif // PPPART_H
