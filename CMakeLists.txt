cmake_minimum_required(VERSION 3.16)

set(FLAGS -std=c++17 -O3 -Wall -g)
set(CMAKE_CXX_COMPILER g++)

add_compile_options(${FLAGS})

project(POP VERSION 0.1 LANGUAGES CXX)

file(GLOB_RECURSE SRC ${CMAKE_SOURCE_DIR}/source/*.cpp)

find_package(GTest REQUIRED)

add_subdirectory(${CMAKE_SOURCE_DIR}/lib)

add_executable(program main.cpp)
# add_executable(runTests test/test_heap.cpp)

target_include_directories(program PUBLIC BEFORE ${CMAKE_SOURCE_DIR}/include)
# target_include_directories(runTests PUBLIC BEFORE ${CMAKE_SOURCE_DIR}/include)


target_link_libraries(program PUBLIC maze)
# target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
