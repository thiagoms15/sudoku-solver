cmake_minimum_required(VERSION 3.5)

project(sudoku_solver_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(
                    "../techniques/"
                    "../techniques/simple/"
                    "../techniques/backtracking/"
                   )

file(GLOB SOURCES
    "../techniques/simple/*.cpp"
    "../techniques/backtracking/*.cpp"
    )

add_executable(sudoku_solver_test main.cpp ${SOURCES})
target_link_libraries(sudoku_solver_test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
