#-------------------------------------------------
#
# Project created by QtCreator 2014-11-08T22:47:22
#
#-------------------------------------------------

QT       += core gui

QT += widgets
QT += bluetooth

CONFIG += c++11
DEFINES += __GXX_EXPERIMENTAL_CXX0X__
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bluelock
TEMPLATE = app


SOURCES += main.cpp\
        bluelockmain.cpp \
    bluelockservice.cpp \
    bluelockcoordinator.cpp \
    bluelockif.cpp \
    bluelocklinux.cpp \
    bluelockwindows.cpp

HEADERS  += bluelockmain.h \
    bluelockservice.h \
    bluelockwindows.h \
    bluelocklinux.h \
    bluelockif.h \
    bluelockcoordinator.h

FORMS    += bluelockmain.ui
