#-------------------------------------------------
#
# Project created by QtCreator 2019-03-30T21:30:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Base1F
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
        main.cpp \
        dialog.cpp \
    background.cpp \
    coordinate.cpp \
    entity.cpp \
    moon.cpp \
    score.cpp \
    stickman.cpp

HEADERS += \
        dialog.h \
    background.h \
    coordinate.h \
    entity.h \
    moon.h \
    score.h \
    stickman.h

FORMS += \
        dialog.ui

DISTFILES += \
    ../build-INFO3220-Desktop_Qt_5_9_4_MinGW_32bit-Debug/config.txt

RESOURCES += \
    resources.qrc
