#-------------------------------------------------
#
# Project created by QtCreator 2010-06-17T14:41:11
#
#-------------------------------------------------

TARGET = spi_cmd_test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

LIBS += -L/usr/local/lib -liqrf -L/usr/lib/i386-linux-gnu/ -lusb-1.0
