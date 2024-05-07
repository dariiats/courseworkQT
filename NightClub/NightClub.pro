#-------------------------------------------------
#
# Project created by QtCreator 2024-03-28T20:45:14
#
#-------------------------------------------------

QT       += core gui
QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NightClub
TEMPLATE = app


SOURCES += main.cpp\
        startwindow.cpp \
    guestwindow.cpp \
    signin.cpp \
    adminwindow.cpp \
    menuforguest.cpp \
    menu.cpp \
    mainmenu.cpp \
    barmenu.cpp \
    dancefloor.cpp \
    dancing.cpp \
    waiter.cpp \
    response.cpp \
    notification.cpp \
    workers.cpp \
    newnameworker.cpp \
    orders.cpp \
    rewiewsadmin.cpp \
    ordermusic.cpp

HEADERS  += startwindow.h \
    guestwindow.h \
    signin.h \
    adminwindow.h \
    menuforguest.h \
    menu.h \
    mainmenu.h \
    barmenu.h \
    dancefloor.h \
    dancing.h \
    ordermusic.h \
    waiter.h \
    response.h \
    notification.h \
    workers.h \
    newnameworker.h \
    orders.h \
    rewiewsadmin.h

FORMS    += startwindow.ui \
    guestwindow.ui \
    signin.ui \
    adminwindow.ui \
    menuforguest.ui \
    menu.ui \
    mainmenu.ui \
    barmenu.ui \
    dancefloor.ui \
    dancing.ui \
    ordermusic.ui \
    waiter.ui \
    response.ui \
    notification.ui \
    workers.ui \
    newnameworker.ui \
    orders.ui \
    rewiewsadmin.ui

RESOURCES += \
    imagies.qrc
