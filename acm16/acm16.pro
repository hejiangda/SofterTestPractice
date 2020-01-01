TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
#QMAKE_CXXFLAGS  += -coverage

SOURCES += \
        main.cpp
#Libraries
unix: CONFIG += link_pkgconfig

#GoogleTest
unix: PKGCONFIG += gtest

