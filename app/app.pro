TEMPLATE = app
QT -= gui
QT += network websockets
TARGET = logger_app


INCLUDEPATH +=  ../betterlib/include

HEADERS += *.h

SOURCES += *.cpp

LIBS += -L../betterlib/bin \
        -lbetter

