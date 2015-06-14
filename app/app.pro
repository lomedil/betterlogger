TEMPLATE = app
QT -= gui
TARGET = logger_app


INCLUDEPATH +=  ../betterlib/include \
                ../betterlib/include/appenders

SOURCES += \
    main.cpp

LIBS += -L../betterlib/bin \
        -lbetter

