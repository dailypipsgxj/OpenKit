#-------------------------------------------------
#
# Project created by QtCreator 2015-03-09T01:57:08
#
#-------------------------------------------------

QT       += network sql xml testlib

QT       -= gui
CONFIG   += c++11
INCLUDEPATH = include
TARGET = QuantKit
TEMPLATE = lib

DEFINES += QUANTKIT_LIBRARY

SOURCES +=\
    src/Event/Ask.cpp \
    src/Event/Bid.cpp \
    src/Event/OnConnect.cpp \
    src/Event/OnDisconnect.cpp \
    src/Event/Tick.cpp \
    src/Event/Trade.cpp \
    src/Event.cpp \
    test/test_event.cpp

HEADERS +=\
    include/QuantKit/Event/Ask.h \
    include/QuantKit/Event/Bid.h \
    include/QuantKit/EventType.h \
    include/QuantKit/Event/OnConnect.h \
    include/QuantKit/Event/OnDisconnect.h \
    include/QuantKit/Event/Tick.h \
    include/QuantKit/Event/Tick_p.h \
    include/QuantKit/Event/Trade.h \
    include/QuantKit/Event.h \
    include/QuantKit/Event_p.h \
    include/QuantKit/IProvider.h \
    include/QuantKit/quantkit_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
