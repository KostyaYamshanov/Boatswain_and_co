QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    icon.cpp \
    authorization.cpp \
    getpath.cpp \
    main.cpp \
    mainwindow.cpp \
    signup.cpp \
    user.cpp

HEADERS += \
    getpath.h \
    authorization.h \
    getpath.h \
    icon.h \
    mainwindow.h \
    signup.h \
    user.h

FORMS += \
    authorization.ui \
    mainwindow.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target