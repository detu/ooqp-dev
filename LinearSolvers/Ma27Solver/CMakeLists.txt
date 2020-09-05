target_sources(ooqpRun
        PRIVATE
           Ma27Solver.h
           Ma27Solver.cpp)

target_include_directories(ooqpRun PRIVATE ${CMAKE_CURRENT_LIST_DIR})