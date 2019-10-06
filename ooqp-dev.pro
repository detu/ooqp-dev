QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

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
    $$PWD/src/DenseLinearAlgebra/*.h \
    $$PWD/src/LinearSolvers/Ma27Solver/*.h \
    $$PWD/src/LinearSolvers/Ma57Solver/*.h \
    $$PWD/src/QpBound/*.h \
    $$PWD/src/QpGen/*.h \
    $$PWD/src/QpSolvers/*.h \
    $$PWD/src/Readers/*.h \
    $$PWD/src/SparseLinearAlgebra/*.h \
    $$PWD/src/Utilities/*.h \
    $$PWD/src/Vector/*.h \     

SOURCES += \
    $$PWD/*.cpp \
    $$PWD/src/Abstract/*.cpp \
    $$PWD/src/DenseLinearAlgebra/*.cpp \
    $$PWD/src/LinearSolvers/Ma27Solver/*.cpp \
    $$PWD/src/LinearSolvers/Ma57Solver/*.cpp \
    $$PWD/src/QpBound/*.cpp \
    $$PWD/src/QpGen/*.cpp \
    $$PWD/src/QpSolvers/*.cpp \
    $$PWD/src/Readers/*.cpp \
    $$PWD/src/SparseLinearAlgebra/*.cpp \
    $$PWD/src/Utilities/*.cpp \
    $$PWD/src/Vector/*.cpp \




win32: LIBS += -L$$PWD/lib/ -lopenblas

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/lib/openblas.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/lib/libopenblas.a



LIBS += -L$$PWD/../../Downloads/coinhsl-2015.06.23/.libs/ -llibcoinhsl

INCLUDEPATH += $$PWD/../../Downloads/coinhsl-2015.06.23/.libs
DEPENDPATH += $$PWD/../../Downloads/coinhsl-2015.06.23/.libs
