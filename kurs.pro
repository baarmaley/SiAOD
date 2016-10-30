#-------------------------------------------------
#
# Project created by QtCreator 2015-03-10T19:19:47
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kurs
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    group.cpp \
    vertexgraph.cpp \
    graphview.cpp \
    myelips.cpp \
    pointtopoint.cpp

HEADERS  += mainwindow.h \
    group.h \
    vertexgraph.h \
    graphview.h \
    myelips.h \
    pointtopoint.h

FORMS    += mainwindow.ui \
    graphview.ui
