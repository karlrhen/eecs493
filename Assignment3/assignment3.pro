#-------------------------------------------------
#
# Project created by QtCreator 2014-03-19T20:15:37
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = assignment4
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        boximage.cpp \
        imagecollector.cpp \
    deleteallcommand.cpp \
    deleteimagecommand.cpp \
    addcollectioncommand.cpp \
    addimagecommand.cpp \
    flickrcollector.cpp



HEADERS  += mainwindow.h \
            boximage.h \
            imagecollector.h\
    deleteallcommand.h \
    deleteimagecommand.h \
    addcollectioncommand.h \
    addimagecommand.h \
    flickrcollector.h

FORMS    += mainwindow.ui
