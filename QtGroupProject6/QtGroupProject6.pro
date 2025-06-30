QT       += core gui

QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    countdown.cpp \
    homepage.cpp \
    main.cpp \
    mainwindow.cpp \
    mode.cpp \
    settingspage.cpp \
    teampage.cpp \
    tiantipage1.cpp \
    tiantipage2.cpp \
    tiantipage3.cpp \
    tiantipage4.cpp \
    totalmainwindow.cpp \
    totiantipage.cpp \
    wordlib.cpp

HEADERS += \
    countdown.h \
    homepage.h \
    mainwindow.h \
    mode.h \
    settingspage.h \
    teampage.h \
    tiantipage1.h \
    tiantipage2.h \
    tiantipage3.h \
    tiantipage4.h \
    totalmainwindow.h \
    totiantipage.h \
    wordlib.h

FORMS += \
    homepage.ui \
    mode.ui \
    settingspage.ui \
    teampage.ui \
    totalmainwindow.ui \
    totiantipage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
