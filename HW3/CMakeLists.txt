cmake_minimum_required(VERSION 3.10)
project(HW3_FilterIterator)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(hw3 main.cpp
        iterator/filter_integer_iterator.h)