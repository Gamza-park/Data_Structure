cmake_minimum_required(VERSION 3.9.4)
project(data_structure)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(recursive recursive_fun.cpp)
add_executable(selectionSort_fun selectionSort_fun.cpp)
add_executable(insertionSort_fun insertionSort_fun.cpp)
add_executable(bubbleSort_fun bubbleSort_fun.cpp)
add_executable(set set.cpp)
add_executable(bit_set bit_set.cpp)