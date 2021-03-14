#Lab 2 by Xiang WEI

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractshape.cpp \
    canvas.cpp \
    ellipse.cpp \
    line.cpp \
    main.cpp \
    mainwindow.cpp \
    rect.cpp

HEADERS += \
    abstractshape.h \
    canvas.h \
    ellipse.h \
    line.h \
    mainwindow.h \
    rect.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
