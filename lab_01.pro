TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Person.cpp \
        PersonKeeper.cpp \
        Stack.cpp \
        main.cpp

HEADERS += \
    EStackEmpty.h \
    EStackException.h \
    Person.h \
    PersonKeeper.h \
    Stack.h

DISTFILES +=
