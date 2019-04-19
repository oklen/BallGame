#-------------------------------------------------
#
# Project created by QtCreator 2019-03-23T16:03:50
#
#-------------------------------------------------

QT       += core gui widgets multimedia

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
    Widgets/widget.cpp \
    Widgets/bound.cpp \
    Widgets/hole.cpp \
    Widgets/object.cpp \
    Widgets/ballobject.cpp \
    Widgets/ball.cpp \
    Widgets/gamemanger.cpp \
    Widgets/testboard.cpp \
    Widgets/vector2.cpp \
    Widgets/rounder.cpp \
    Widgets/player.cpp \
    Widgets/club.cpp \
    Widgets/shootline.cpp \
    Widgets/lineobject.cpp \
    Widgets/mainwindow.cpp \
    Widgets/perseonstate.cpp \
    Widgets/stateshower.cpp \
    Widgets/boundline.cpp \
    StateMachine/gamestate.cpp \
    StateMachine/acquirered.cpp \
    StateMachine/acquirecolor.cpp \
    StateMachine/acquirefailed.cpp \
    Widgets/globalcontrol.cpp \
    Widgets/vgcontrol.cpp \
    Resouces/bound_shape.cpp \
    Resouces/gjk_al.cpp \
    StateMachine/acquireorder.cpp \
    Widgets/controlbutton.cpp \
    Widgets/pausemenu.cpp \
    Widgets/textlabel.cpp \
    Resouces/ball_bank.cpp \
    Resouces/musicmanger.cpp \
    Test/gjk_test.cpp
    
HEADERS += \
    Widgets/widget.h \
    Widgets/bound.h \
    Widgets/hole.h \
    Widgets/object.h \
    Widgets/ballobject.h \
    Widgets/ball.h \
    Widgets/gamemanger.h \
    Widgets/testboard.h \
    Widgets/vector2.h \
    Widgets/rounder.h \
    Widgets/player.h \
    Widgets/club.h \
    Widgets/shootline.h \
    Widgets/lineobject.h \
    Widgets/mainwindow.h \
    Widgets/perseonstate.h \
    Widgets/stateshower.h \
    Widgets/boundline.h \
    StateMachine/gamestate.h \
    StateMachine/acquirered.h \
    StateMachine/acquirecolor.h \
    StateMachine/acquirefailed.h \
    Widgets/globalcontrol.h \
    Widgets/vgcontrol.h \
    StateMachine/acquireorder.h \
    Widgets/controlbutton.h \
    Widgets/pausemenu.h \
    Widgets/textlabel.h \
    Resouces/ball_bank.h \
    Resouces/bound_shape.h \
    Resouces/gjk_al.h  \
    Resouces/musicmanger.h \
    Test/gjk_test.h

FORMS += \
        widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
