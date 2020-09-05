cmake_minimum_required(VERSION 3.15)
project(ooqp-dev VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake_modules)
find_package(HSL REQUIRED)
include_directories(${HSL_INCLUDE_DIR})

find_package(BLAS REQUIRED)
include_directories(${BLAS_INCLUDE_DIR})

add_executable(ooqpRun main.cpp)

add_subdirectory(Abstract)
add_subdirectory(Vector)
add_subdirectory(LinearSolvers/Ma27Solver)
add_subdirectory(LinearSolvers/Ma57Solver)
add_subdirectory(QpExample)
add_subdirectory(QpGen)
add_subdirectory(QpSolvers)
add_subdirectory(Readers)
add_subdirectory(SparseLinearAlgebra)
add_subdirectory(DenseLinearAlgebra)
add_subdirectory(Utilities)

target_link_libraries(ooqpRun ${HSL_LIBRARIES} ${BLAS_LIBRARIES})

#include_directories(Abstract)
#include_directories(Vector)
#include_directories(LinearSolvers/Ma27Solver)
#include_directories(LinearSolvers/Ma57Solver)
#include_directories(QpExample)
#include_directories(QpGen)
#include_directories(QpSolvers)
#include_directories(Readers)
#include_directories(SparseLinearAlgebra)
#include_directories(Utilities)

#target_sources(ooqp-dev
#        PRIVATE Abstract Vector LinearSolvers/Ma27Solver LinearSolvers/Ma57Solver QpExample QpGen QpSolvers Readers SparseLinearAlgebra Utilities)

#include_directories(Abstract)
#include_directories(Vector)
#include_directories(LinearSolvers/Ma27Solver)
#include_directories(LinearSolvers/Ma57Solver)
#include_directories(QpExample)
#include_directories(QpGen)
#include_directories(QpSolvers)
#include_directories(Readers)
#include_directories(SparseLinearAlgebra)
#include_directories(Utilities)

#add_executable(HelloWorld main.cpp Abstract/Data.cpp Abstract/Data.h Abstract/SmartPointer.h Abstract/IotrRefCount.cpp Abstract/IotrRefCount.h Abstract/DoubleLinearSolver.h Abstract/DoubleMatrix.h Abstract/DoubleMatrixHandle.h Vector/OoqpVectorHandle.h Vector/OoqpVector.cpp Vector/OoqpVector.h Vector/SimpleVector.cpp Vector/SimpleVector.h Vector/SimpleVectorHandle.h Vector/VectorUtilities.cpp Vector/VectorUtilities.h Abstract/DoubleMatrixTypes.h Abstract/LinearAlgebraPackage.h Abstract/LinearSystem.h Abstract/OoqpMonitor.cpp Abstract/OoqpMonitor.h Abstract/OoqpMonitorData.h Abstract/OoqpStartStrategy.h Abstract/OoqpVersion.cpp Abstract/OoqpVersion.h Abstract/ProblemFormulation.h Abstract/Residuals.h Abstract/Solver.cpp Abstract/Solver.h Abstract/Status.cpp Abstract/Status.h Abstract/Variables.cpp Abstract/Variables.h LinearSolvers/Ma27Solver/Ma27Solver.cpp LinearSolvers/Ma27Solver/Ma27Solver.h SparseLinearAlgebra/SparseGenMatrix.cpp SparseLinearAlgebra/SparseGenMatrix.h SparseLinearAlgebra/SparseGenMatrixHandle.h SparseLinearAlgebra/SparseLinearAlgebraPackage.cpp SparseLinearAlgebra/SparseLinearAlgebraPackage.h SparseLinearAlgebra/SparseStorage.cpp SparseLinearAlgebra/SparseStorage.h SparseLinearAlgebra/SparseStorageHandle.h SparseLinearAlgebra/SparseSymMatrix.cpp SparseLinearAlgebra/SparseSymMatrix.h SparseLinearAlgebra/SparseSymMatrixHandle.h LinearSolvers/Ma57Solver/Ma57Solver.cpp LinearSolvers/Ma57Solver/Ma57Solver.h QpGen/QpGen.cpp QpGen/QpGen.h QpGen/QpGenData.cpp QpGen/QpGenData.h QpGen/QpGenLinsys.cpp QpGen/QpGenLinsys.h QpGen/QpGenResiduals.cpp QpGen/QpGenResiduals.h QpGen/QpGenVars.cpp QpGen/QpGenVars.h QpGen/QpGenSparseLinsys.cpp QpGen/QpGenSparseLinsys.h QpGen/QpGenSparseMa27.cpp QpGen/QpGenSparseMa27.h QpGen/QpGenSparseMa57.cpp QpGen/QpGenSparseMa57.h QpGen/QpGenSparseSeq.cpp QpGen/QpGenSparseSeq.h QpSolvers/GondzioSolver.cpp QpSolvers/GondzioSolver.h QpSolvers/MehrotraSolver.cpp QpSolvers/MehrotraSolver.h Utilities/OoqpBlas.h Utilities/drand.cpp Utilities/sort.cpp)

#target_link_libraries(HelloWorld ${HSL_LIBRARIES} ${BLAS_LIBRARIES})
