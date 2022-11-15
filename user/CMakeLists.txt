cmake_minimum_required(VERSION 3.20)
project(userLabaProc)

set(CMAKE_CXX_STANDARD 20)


add_executable(userLabaProc main.cpp)
add_library(libkill STATIC IMPORTED)
set_target_properties(libkill PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/../labaProc)
set_target_properties(libkill PROPERTIES IMPORTED_LOCATION  ${CMAKE_CURRENT_SOURCE_DIR}/../labaProc/cmake-build-debug/liblibkill.a)
target_link_libraries(userLabaProc PUBLIC libkill)
