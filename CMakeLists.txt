cmake_minimum_required(VERSION 3.1.0)

project(cutils C CXX ASM)

include(cmake/macro.cmake)

include_directories(include)

add_subdirectory(src)

enable_testing()