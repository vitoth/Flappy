#-------------------------------------------------
#
# Project created by QtCreator 2015-08-16T11:21:17
#
#-------------------------------------------------

QT       += core gui multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTflappy
TEMPLATE = app


SOURCES += main.cpp \
    enemy.cpp \
    game.cpp \
    player.cpp \
    score.cpp

HEADERS  += \
    enemy.h \
    game.h \
    player.h \
    score.h

RESOURCES += \
    snd.qrc
