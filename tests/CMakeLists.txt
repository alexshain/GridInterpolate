cmake_minimum_required(VERSION 3.10)
project(MyTests)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

find_package(GTest REQUIRED)
include_directories(/opt/homebrew/Cellar/googletest/1.15.2/include)
link_directories(/opt/homebrew/Cellar/googletest/1.15.2/lib)

add_executable(int_test DownscaleTest.cpp 
            ../cpp/src/ClosestNeighborGridInterpolation.cpp
            ../cpp/src/Grid.cpp
            ../cpp/src/LinearGridInterpolation.cpp)

target_link_libraries(int_test gtest gtest_main pthread)

add_test(NAME IntTests COMMAND int_test)
