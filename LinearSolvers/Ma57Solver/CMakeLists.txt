target_sources(ooqpRun
        PRIVATE
           Ma57Solver.h
           Ma57Solver.cpp)

target_include_directories(ooqpRun PRIVATE ${CMAKE_CURRENT_LIST_DIR})