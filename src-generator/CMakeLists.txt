cmake_minimum_required(VERSION 3.5)

#TODO: create as lib
project(generator_sudoku_matrix LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

file(GLOB SOURCES
    "getApi.cpp"
    )

add_executable (generator_sudoku_matrix main.cpp ${SOURCES})
target_link_libraries(generator_sudoku_matrix ${CURL_LIBRARIES})

