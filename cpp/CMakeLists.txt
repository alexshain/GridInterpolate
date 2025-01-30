cmake_minimum_required(VERSION 3.29)

project(quasi-one-dimensional LANGUAGES CXX)

# Стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Исполняемый файл с указанием исходных файлов
add_executable(Interpolate 
			src/main.cpp
			src/ClosestNeighborGridInterpolation.cpp
			src/Grid.cpp
			src/LinearGridInterpolation.cpp)

