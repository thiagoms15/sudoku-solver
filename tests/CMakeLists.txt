cmake_minimum_required(VERSION 3.5)

project(example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(example main.cpp)
target_link_libraries(example ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
