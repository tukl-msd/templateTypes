QT -= core
QT -= gui
CONFIG += console
CONFIG -= app_bundle

CONFIG += c++11

TARGET = templateTypes

TEMPLATE = app

SOURCES += main.cpp

HEADERS += basetype.h \
    bittype.h

#QMAKE_CXXFLAGS += -fprofile-instr-generate -fcoverage-mapping
#QMAKE_LFLAGS +=  -fprofile-instr-generate -fcoverage-mapping

QMAKE_CXXFLAGS +=  -fprofile-arcs -ftest-coverage -fPIC -O0
QMAKE_LFLAGS +=  -fprofile-arcs -ftest-coverage -fPIC -O0

#macx{
#    LIBS += -L /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/8.0.0/lib/darwin -lclang_rt.profile_osx
#}
