target_sources(ooqpRun
        PRIVATE
           GondzioSolver.h
           GondzioSolver.cpp
           MehrotraSolver.h
           MehrotraSolver.cpp)

target_include_directories(ooqpRun PRIVATE ${CMAKE_CURRENT_LIST_DIR})