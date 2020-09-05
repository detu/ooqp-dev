target_sources(ooqpRun
        PRIVATE
           drand.cpp
           OoqpBlas.h
           sort.cpp)

target_include_directories(ooqpRun PRIVATE ${CMAKE_CURRENT_LIST_DIR})