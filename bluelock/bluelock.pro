#-------------------------------------------------
#
# Project created by QtCreator 2014-11-08T22:47:22
#
#-------------------------------------------------

QT       += core gui

QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bluelock
TEMPLATE = app


SOURCES += main.cpp\
        bluelockmain.cpp \
    lockerwindows.cpp \
    lockerlinux.cpp \
    lockercoordinator.cpp \
    lockerif.cpp

HEADERS  += bluelockmain.h \
    lockerwindows.h \
    lockerlinux.h \
    lockercoordinator.h \
    lockerif.h

FORMS    += bluelockmain.ui
