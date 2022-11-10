cmake_minimum_required(VERSION 3.16)

set(FLAGS -std=c++17 -O3 -Wall -g)
set(CMAKE_CXX_COMPILER g++)

add_compile_options(${FLAGS})

project(POP VERSION 0.1 LANGUAGES CXX)

file(GLOB_RECURSE SRC ${CMAKE_SOURCE_DIR}/source/*.cpp)

find_package(GTest REQUIRED)

add_subdirectory(${CMAKE_SOURCE_DIR}/lib)

# add_executable(program main.cpp)
add_executable(runGraphTest test/test_graph.cpp)
add_executable(runDijkstraTest test/test_dijkstra.cpp)
add_executable(runBrutTest test/test_brut.cpp)
add_executable(runMain main.cpp)
add_executable(runAstarTest test/test_astar.cpp)

# target_include_directories(program PUBLIC BEFORE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(runGraphTest PUBLIC BEFORE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(runDijkstraTest PUBLIC BEFORE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(runBrutTest PUBLIC BEFORE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(runMain PUBLIC BEFORE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(runAstarTest PUBLIC BEFORE ${CMAKE_SOURCE_DIR}/include)


# target_link_libraries(program PUBLIC search_comp)
target_link_libraries(runGraphTest search_comp ${GTEST_LIBRARIES} pthread)
target_link_libraries(runDijkstraTest search_comp ${GTEST_LIBRARIES} pthread)
target_link_libraries(runBrutTest search_comp ${GTEST_LIBRARIES} pthread)
target_link_libraries(runMain search_comp ${GTEST_LIBRARIES} pthread)
target_link_libraries(runAstarTest search_comp ${GTEST_LIBRARIES} pthread)
