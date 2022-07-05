QT       += core gui network opengl widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets charts

RESOURCES = breeze.qrc

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    category.cpp \
    main.cpp \
    nastaveni.cpp \
    networksql.cpp \
    pppart.cpp \
    prijem_novy_1.cpp \
    vydej_1.cpp

HEADERS += \
    category.h \
    nastaveni.h \
    networksql.h \
    pppart.h \
    prijem_novy_1.h \
    vydej_1.h

FORMS += \
    category.ui \
    input_element1.ui \
    input_element2.ui \
    input_element3.ui \
    input_element4.ui \
    input_element5.ui \
    input_element6.ui \
    input_element7.ui \
    nastaveni.ui \
    pppart.ui \
    prijem_novy_1.ui \
    vyber_skladu.ui \
    vydej_1.ui

TRANSLATIONS += \
    PPPart_cs_CZ.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
