#-------------------------------------------------
#
# Project created by QtCreator 2016-02-05T00:02:51
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hw4v3
TEMPLATE = app


SOURCES += main.cpp \
    player.cpp \
    bullet.cpp \
    falling.cpp \
    enemy.cpp \
    game.cpp \
    welcomepage.cpp \
    doge.cpp \
    instruction.cpp \
    gameover.cpp

HEADERS  += \
    player.h \
    bullet.h \
    falling.h \
    enemy.h \
    game.h \
    welcomepage.h \
    doge.h \
    instruction.h \
    gameover.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc \
    music.qrc

DISTFILES += \
    background copy.jpg
