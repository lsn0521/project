#-------------------------------------------------
#
# Project created by QtCreator 2022-07-21T21:49:39
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = login
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        consolewindow.cpp \
        itemwin.cpp \
        main.cpp \
        menu_addwindow.cpp \
        orderwindow.cpp \
        select_menuwindow.cpp \
        widget.cpp

HEADERS += \
        consolewindow.h \
        itemwin.h \
        menu_addwindow.h \
        orderwindow.h \
        select_menuwindow.h \
        widget.h

FORMS += \
        consolewindow.ui \
        itemwin.ui \
        menu_addwindow.ui \
        orderwindow.ui \
        select_menuwindow.ui \
        widget.ui

RESOURCES += \
    qss.qrc \
    pic.qrc \
    usr.qrc
