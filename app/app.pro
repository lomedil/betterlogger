TEMPLATE = app
QT -= gui
QT += network websockets
TARGET = logger_app


INCLUDEPATH +=  ../betterlib/include \
                ../betterlib/include/appenders

HEADERS += *.h

SOURCES += *.cpp

LIBS += -L../betterlib/bin \
        -lbetter

