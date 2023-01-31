// Debian11 -> Missing OpenGL -> apt-file search "/usr/include/GL/gl.h" -> apt-file search "/usr/include/GL/gl.h"
//          -> Missing XCB -> /Qt/6.5.0/gcc_64/plugins/platforms$ ldd libqxcb.so | grep "not" -> sudo apt install libxcb-cursor-dev libxcb-util-dev
//                         -> sudo apt install '^libxcb.*-dev' libx11-xcb-dev libglu1-mesa-dev libxrender-dev libxi-dev libxkbcommon-dev libxkbcommon-x11-dev

#include "pppart.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setOrganizationName("PP");
    a.setOrganizationDomain("pppart.vcpavel31.cz");
    a.setApplicationName("PPPart");

    // set stylesheet
    QFile file(":/dark/stylesheet.qss");
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream stream(&file);
    a.setStyleSheet(stream.readAll());


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
