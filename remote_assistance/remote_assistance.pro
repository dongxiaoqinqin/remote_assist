QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = remote_assistance
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget

SOURCES += \
        main.cpp \
    mainwindow.cpp \
    askhelp.cpp \
    helpother.cpp

RESOURCES +=         resources.qrc

HEADERS += \
    mainwindow.h \
    askhelp.h \
    helpother.h
