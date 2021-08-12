cmake_minimum_required(VERSION 3.5)

project(test_simple LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS}
                    "./.."
                   )

file(GLOB SOURCES "../*.cpp")

add_executable(test_simple main.cpp ${SOURCES})
target_link_libraries(test_simple ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
