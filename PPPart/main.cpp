#include "pppart.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setOrganizationName("PP");
    a.setOrganizationDomain("pppart.vcpavel31.cz");
    a.setApplicationName("PPPart");

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "PPPart_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    PPPart w;
    w.show();
    return a.exec();
}
