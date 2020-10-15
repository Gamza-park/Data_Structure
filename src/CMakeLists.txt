cmake_minimum_required(VERSION 3.9.4)
project(data_structure)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(recursive recursive_fun.cpp)
add_executable(sorting sorting_fun.cpp)