target_sources(ooqpRun
        PRIVATE
            DenseGenMatrix.h
            DenseGenMatrix.cpp
            DenseGenMatrixHandle.h
            DenseLinearAlgebraPackage.h
            DenseLinearAlgebraPackage.cpp
            DenseStorage.h
            DenseStorage.cpp
            DenseStorageHandle.h
            DenseSymMatrix.h
            DenseSymMatrix.cpp
            DenseSymMatrixHandle.h
            DeSymIndefSolver.h
            DeSymIndefSolver.cpp
            DeSymPSDSolver.h
            DeSymPSDSolver.cpp)

target_include_directories(ooqpRun PRIVATE ${CMAKE_CURRENT_LIST_DIR})