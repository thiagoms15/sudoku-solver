cmake_minimum_required(VERSION 3.5)

project(sudoku_solver LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_COMPILER clang)
set(CMAKE_C_COMPILER_TARGET ${CLANG_TARGET_TRIPLE})
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_COMPILER_TARGET ${CLANG_TARGET_TRIPLE})
set(CMAKE_ASM_COMPILER clang)
set(CMAKE_ASM_COMPILER_TARGET ${CLANG_TARGET_TRIPLE})

# Specify compiler flags
set(CMAKE_C_FLAGS "-Wall -O3 ${ARCH_FLAGS}" CACHE STRING "Common flags for C compiler")
set(CMAKE_CXX_FLAGS "-Wall -std=c++20 -O3 -fno-exceptions -fno-rtti -fno-threadsafe-statics ${ARCH_FLAGS}" CACHE STRING "Common flags for C++ compiler")
set(CMAKE_ASM_FLAGS "-Wall ${ARCH_FLAGS} -x assembler-with-cpp" CACHE STRING "Common flags for assembler")
set(CMAKE_EXE_LINKER_FLAGS "-nostartfiles -Wl,-Map,kernel.map,--gc-sections -fuse-linker-plugin -Wl,--use-blx --specs=nano.specs --specs=nosys.specs" CACHE STRING "")


include_directories(
                    "../techniques/"
                    "../techniques/simple/"
                    "../techniques/backtracking/"
                   )

file(GLOB SOURCES
    "../techniques/*.cpp"
    "../techniques/simple/*.cpp"
    "../techniques/backtracking/*.cpp"
    )

add_executable(sudoku_solver main.cpp ${SOURCES})
target_link_libraries(sudoku_solver)
