#-------------------------------------------------
#
# Project created by QtCreator 2017-03-26T14:22:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ctripui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    loginui.cpp \
    ../code/chotel.cpp \
    ../code/hotelmanage.cpp \
    ../code/hotelplc.cpp \
    ../code/hoteluser.cpp \
    ../code/labfile.cpp \
    ../code/launcher.cpp \
    ../code/signiu.cpp \
    roomui.cpp \
    orderui.cpp \
    mainn.cpp \
    userui.cpp \
    roomsuserui.cpp \
    ordering.cpp \
    orderuser.cpp \
    searchrooms.cpp \
    uppwd.cpp

HEADERS  += \
    loginui.h \
    ../code/chotel.h \
    ../code/hotelmanage.h \
    ../code/hotelplc.h \
    ../code/hoteluser.h \
    ../code/labfile.h \
    ../code/signiu.h \
    roomui.h \
    orderui.h \
    mainn.h \
    userui.h \
    roomsuserui.h \
    ordering.h \
    orderuser.h \
    searchrooms.h \
    uppwd.h

FORMS    += \
    loginui.ui \
    roomui.ui \
    orderui.ui \
    mainn.ui \
    userui.ui \
    roomsuserui.ui \
    ordering.ui \
    orderuser.ui \
    searchrooms.ui \
    uppwd.ui

RC_FILE = img.rc

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = icTrip
TEMPLATE = app
SOURCES += main.cpp
HEADERS  +=
FORMS    +=

DISTFILES += \
    img.ico \
    question.ico

RESOURCES += \
    img.qrc

