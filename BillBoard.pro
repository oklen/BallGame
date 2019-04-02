#-------------------------------------------------
#
# Project created by QtCreator 2019-03-23T16:03:50
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = BillBoard
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        widget.cpp \
    bound.cpp \
    hole.cpp \
    object.cpp \
    ballobject.cpp \
    ball.cpp \
    gamemanger.cpp \
    testboard.cpp \
    vector2.cpp \
    Widgets/rounder.cpp \
    player.cpp \
    club.cpp \
    shootline.cpp \
    lineobject.cpp \
    mainwindow.cpp \
    perseonstate.cpp \
    stateshower.cpp \
    boundline.cpp \
    StateMachine/gamestate.cpp \
    StateMachine/acquirered.cpp \
    StateMachine/acquirecolor.cpp \
    StateMachine/acquirefailed.cpp \
    globalcontrol.cpp \
    vgcontrol.cpp \
    StateMachine/acquireorder.cpp \
    Widgets/controlbutton.cpp \
    Widgets/pausemenu.cpp \
    Widgets/textlabel.cpp \
    Resouces/ball_bank.cpp

HEADERS += \
        widget.h \
    bound.h \
    hole.h \
    object.h \
    ballobject.h \
    ball.h \
    gamemanger.h \
    testboard.h \
    vector2.h \
    Widgets/rounder.h \
    player.h \
    club.h \
    shootline.h \
    lineobject.h \
    mainwindow.h \
    perseonstate.h \
    stateshower.h \
    boundline.h \
    StateMachine/gamestate.h \
    StateMachine/acquirered.h \
    StateMachine/acquirecolor.h \
    StateMachine/acquirefailed.h \
    globalcontrol.h \
    vgcontrol.h \
    StateMachine/acquireorder.h \
    Widgets/controlbutton.h \
    Widgets/pausemenu.h \
    Widgets/textlabel.h \
    Resouces/ball_bank.h

FORMS += \
        widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
