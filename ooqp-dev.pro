QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle
@LIBS += -lgfortran@

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


HEADERS += \
    $$PWD/src/Abstract/*.h \
    $$PWD/src/LinearSolvers/Ma27Solver/*.h \
    $$PWD/src/LinearSolvers/Ma57Solver/*.h \
    $$PWD/src/QpGen/*.h \
    $$PWD/src/QpSolvers/*.h \
    $$PWD/src/Readers/*.h \
    $$PWD/src/SparseLinearAlgebra/*.h \
    $$PWD/src/Utilities/*.h \
    $$PWD/src/Vector/*.h \     

SOURCES += \
    $$PWD/*.cpp \
    $$PWD/src/Abstract/*.cpp \
    $$PWD/src/LinearSolvers/Ma27Solver/*.cpp \
    $$PWD/src/LinearSolvers/Ma57Solver/*.cpp \
    $$PWD/src/QpGen/*.cpp \
    $$PWD/src/QpSolvers/*.cpp \
    $$PWD/src/Readers/*.cpp \
    $$PWD/src/SparseLinearAlgebra/*.cpp \
    $$PWD/src/Utilities/*.cpp \
    $$PWD/src/Vector/*.cpp \


unix:!macx: LIBS += -L$$PWD/../Ipopt-3.12.8/ThirdParty/HSL/lib/ -lcoinhsl

INCLUDEPATH += $$PWD/../Ipopt-3.12.8/ThirdParty/HSL/include
DEPENDPATH += $$PWD/../Ipopt-3.12.8/ThirdParty/HSL/include


unix:!macx: LIBS += -L$$PWD/../OpenBLAS-0.2.20/ -lopenblas

INCLUDEPATH += $$PWD/../OpenBLAS-0.2.20
DEPENDPATH += $$PWD/../OpenBLAS-0.2.20
