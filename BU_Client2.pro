#-------------------------------------------------
#
# Project created by QtCreator 2013-01-17T00:49:30
#
#-------------------------------------------------

QT       += core gui
QT       += network


TARGET = BU_Client2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    clientmaster.cpp \
    clientslave.cpp \
    myfile.cpp

HEADERS  += mainwindow.h \
    login.h \
    clientmaster.h \
    clientslave.h \
    myfile.h

FORMS    += mainwindow.ui \
    login.ui
