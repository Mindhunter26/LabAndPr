include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

INCLUDEPATH += ../WorkingProject

HEADERS += \
        ../WorkingProject/IKeypad.h \
        ../WorkingProject/ILatch.h \
        ../WorkingProject/lockcontroller.h \
        tst_testdivisionbyzero.h

SOURCES += \
        ../WorkingProject/lockcontroller.cpp \
        main.cpp
