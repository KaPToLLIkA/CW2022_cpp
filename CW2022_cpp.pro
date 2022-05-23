QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    model/data_base.cpp \
    model/director.cpp \
    model/iemployee.cpp \
    model/office.cpp \
    model/security.cpp \
    model/teacher.cpp \
    office.cpp \
    slow_list.cpp

HEADERS += \
    mainwindow.h \
    model/data_base.h \
    model/director.h \
    model/iemployee.h \
    model/office.h \
    model/security.h \
    model/teacher.h \
    office.h \
    slow_list.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
