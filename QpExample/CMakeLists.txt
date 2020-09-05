target_sources(ooqpRun
        PRIVATE
           QpExampleData.h
           QpExampleData.cpp
           #QpExampleGondzioDriver.cpp
           QpExampleResids.h
           QpExampleResids.cpp
           QpExampleVars.h
           QpExampleVars.cpp
           QpExampleDense.h
           QpExampleDense.cpp
           QpExampleDenseLinsys.h
           QpExampleDenseLinsys.cpp)

target_include_directories(ooqpRun PRIVATE ${CMAKE_CURRENT_LIST_DIR})