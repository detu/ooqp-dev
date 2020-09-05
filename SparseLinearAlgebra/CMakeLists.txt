target_sources(ooqpRun
        PRIVATE
           SparseGenMatrix.h
           SparseGenMatrix.cpp
           SparseGenMatrixHandle.h
           SparseLinearAlgebraPackage.h
           SparseLinearAlgebraPackage.cpp
           SparseStorage.h
           SparseStorage.cpp
           SparseStorageHandle.h
           SparseStorage.cpp
           SparseSymMatrix.h
           SparseSymMatrix.cpp
           SparseSymMatrixHandle.h)

target_include_directories(ooqpRun PRIVATE ${CMAKE_CURRENT_LIST_DIR})