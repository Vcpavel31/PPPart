QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    nastaveni.cpp \
    pppart.cpp \
    prijem_novy_1.cpp \
    vydej_1.cpp

HEADERS += \
    nastaveni.h \
    pppart.h \
    prijem_novy_1.h \
    vydej_1.h

FORMS += \
    nastaveni.ui \
    pppart.ui \
    prijem_novy_1.ui \
    vydej_1.ui

TRANSLATIONS += \
    PPPart_cs_CZ.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
