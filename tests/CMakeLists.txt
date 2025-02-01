cmake_minimum_required(VERSION 3.10)
project(RescaleTests)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffloat-store")

message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")

enable_testing()

find_package(GTest REQUIRED)
include_directories(/opt/homebrew/Cellar/googletest/1.15.2/include)
link_directories(/opt/homebrew/Cellar/googletest/1.15.2/lib)

add_executable(rescale_test GridRescaleTest.cpp 
            ../cpp/src/ClosestNeighborGridInterpolation.cpp
            ../cpp/src/Grid.cpp
            ../cpp/src/LinearGridInterpolation.cpp)

target_link_libraries(rescale_test gtest gtest_main pthread)

add_test(NAME RecaleTests COMMAND rescale_test)