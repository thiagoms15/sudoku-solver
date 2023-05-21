cmake_minimum_required(VERSION 3.16)

project(SudokuUI LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_AUTOMOC ON)

if(NOT DEFINED INSTALL_BIN_DIR)
    set(INSTALL_BIN_DIR "output")
endif()

set(INSTALL_BIN_DIR "${INSTALL_BIN_DIR}/bin/SudokuUI")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

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

qt_add_executable(sudoku_ui
    window.cpp
    SudokuModel.cpp
    main.cpp
    ${SOURCES}
)

set_target_properties(sudoku_ui PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(sudoku_ui PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Widgets
)

install(TARGETS sudoku_ui
    RUNTIME DESTINATION "${INSTALL_BIN_DIR}"
    BUNDLE DESTINATION "${INSTALL_BIN_DIR}"
    LIBRARY DESTINATION "${INSTALL_BIN_DIR}"
)
