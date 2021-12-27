cmake_minimum_required(VERSION 3.1.0)

project(cutils C CXX ASM)

include(cmake/macro.cmake)

include_directories(include)

enable_testing()
include_directories(${PROJECT_SOURCE_DIR}/external/Catch2/src)

add_subdirectory(external)
add_subdirectory(src)
