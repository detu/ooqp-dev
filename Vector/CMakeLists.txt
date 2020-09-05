target_sources(ooqpRun
        PRIVATE
            OoqpVector.h
            OoqpVector.cpp
            OoqpVectorHandle.h
            SimpleVector.h
            SimpleVector.cpp
            VectorUtilities.h
            VectorUtilities.cpp)

target_include_directories(ooqpRun PRIVATE ${CMAKE_CURRENT_LIST_DIR})