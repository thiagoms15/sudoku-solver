#pragma once
#include <array>
#include <cinttypes>

// N is the size of the 2D matrix N*N
const int N = 9;

// UNASSIGNED is used for empty
// cells in sudoku grid
#define UNASSIGNED 0

struct SudokuTraits {
    using SudokuMatrix = std::array<std::array<int, N>,N>;
    static const uint8_t lines = N;
    static const uint8_t columns = N;

};

namespace SudokuHelper {

    struct Data {
        // 0 means unassigned cells
        SudokuTraits::SudokuMatrix grid = {{ { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
            { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
            { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
            { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
            { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
            { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
            { 0, 0, 5, 2, 0, 6, 3, 0, 0 } }};

        SudokuTraits::SudokuMatrix expected = {{ {3, 1, 6, 5, 7, 8, 4, 9, 2 },
            {5, 2, 9, 1, 3, 4, 7, 6, 8 },
            {4, 8, 7, 6, 2, 9, 5, 3, 1 },
            {2, 6, 3, 4, 1, 5, 9, 8, 7 },
            {9, 7, 4, 8, 6, 3, 1, 2, 5 },
            {8, 5, 1, 7, 9, 2, 6, 4, 3 },
            {1, 3, 8, 9, 4, 7, 2, 5, 6 },
            {6, 9, 2, 3, 5, 1, 8, 7, 4 },
            {7, 4, 5, 2, 8, 6, 3, 1, 9 } }};

        bool compare(const SudokuTraits::SudokuMatrix& grid, const SudokuTraits::SudokuMatrix& expected);

        bool compare() { return compare(grid, expected); };

    };
    /* A utility function to print grid */
    void print(const SudokuTraits::SudokuMatrix& arr);

}
