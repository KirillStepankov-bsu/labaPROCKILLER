cmake_minimum_required(VERSION 3.20)
project(labaPROC)

set(CMAKE_CXX_STANDARD 20)

add_executable(labaPROC killer.cpp)
add_library(libkill
        STATIC
        killer.cpp)