target_sources(ooqpRun
        PRIVATE
            QpGen.h
            QpGen.cpp
            QpGenData.h
            QpGenData.cpp
            QpGenLinsys.h
            QpGenLinsys.cpp
            QpGenResiduals.h
            QpGenResiduals.cpp
            QpGenSparseMa27.h
            QpGenSparseMa27.cpp
            QpGenSparseSeq.h
            QpGenSparseSeq.cpp
            QpGenVars.h
            QpGenVars.cpp
            QpGenSparseMa57.h
            QpGenSparseMa57.cpp
            QpGenSparseLinsys.h
            QpGenSparseLinsys.cpp
            QpGenSparseSeq.h
            QpGenSparseSeq.cpp)

target_include_directories(ooqpRun PRIVATE ${CMAKE_CURRENT_LIST_DIR})