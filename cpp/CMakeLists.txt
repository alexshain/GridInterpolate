cmake_minimum_required(VERSION 3.29)

project(GridRescale LANGUAGES CXX)

# Стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Исполняемый файл с указанием исходных файлов
add_executable(Rescale 
			src/main.cpp
			src/ClosestNeighborGridInterpolation.cpp
			src/Grid.cpp
			src/LinearGridInterpolation.cpp)

