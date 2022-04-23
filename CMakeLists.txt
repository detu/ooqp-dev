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

target_link_libraries(ooqpRun ${HSL_LIBRARIES} ${BLAS_LIBRARIES} ${CMAKE_DL_LIBS})

