cmake_minimum_required(VERSION 3.6)
project(Matrix)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wvla")
set(CMAKE_VERBOSE_MAKEFILE ON)
set(SOURCE_FILES main.cpp Matrix.hpp)
add_executable(Matrix ${SOURCE_FILES})