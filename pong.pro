TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    stage.cpp \
    bat.cpp \
    ball.cpp

LIBS += -L/usr/local/lib -lSDL2

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    main.h \
    stage.h \
    bat.h \
    ball.h

