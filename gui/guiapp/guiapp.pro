#-------------------------------------------------
#
# Project created by QtCreator 2017-06-25T22:04:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = guiapp
TEMPLATE = app

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    debugwindow.cpp \
    table_fragment.cpp \
    16x16/Board/Board16.cpp \
    16x16/Solver/Solver16.cpp \
    9x9/Board/Board9.cpp \
    9x9/Solver/Solver9.cpp \
    window16.cpp \
    launcher.cpp \
    window9.cpp

HEADERS += \
    param.h \
    debugwindow.h \
    table_fragment.h \
    16x16/Board/Board16.hpp \
    16x16/Solver/Solver16.hpp \
    9x9/Board/Board9.hpp \
    9x9/Solver/Solver9.hpp \
    utils.h \
    point.h \
    board.h \
    solver.h \
    window16.h \
    launcher.h \
    window9.h

FORMS += \
    mainwindow.ui \
    debugwindow.ui \
    window16.ui \
    launcher.ui \
    window9.ui
