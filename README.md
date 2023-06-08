# _Sudoku Solver_

<img alt="License" src="https://img.shields.io/static/v1?label=license&message=MIT&color=E51C44&labelColor=0A1033">

This is a sudoku solver program in C++
 
#### Preview

![Home screen animated](images/screen.gif)

___

## :small_blue_diamond: 1. Depedencies
 - C++
 - CMake
 - GTest
 - Qt

___

## :mage_man: 2. How to build

### 2.1. :desktop_computer: Standalone version
```
mkdir build && cd build
cmake ../src-standalone/
make -j$(nprocs)
```

### 2.2. :video_game: Tests
```
mkdir build_tests && cd build_tests
cmake ../tests/
make -j$(nprocs)
```

### 2.3. :alembic: Qt
```
mkdir build_qt && cd build_qt
qt-cmake ../src-qt/
ninja
```
___

## :zombie: 3. TODO :rotating_light:
- Get the grid from the camera;
- Screen to insert a grid by hand;
- GUI using `React Native` <img width="20" alt="React" src="https://reactnative.dev/img/header_logo.svg"> (submodule).

## :page_with_curl: 4. License

This project is under MIT license. Take a look in [LICENSE](LICENSE) for more details.

