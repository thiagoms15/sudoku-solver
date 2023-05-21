#include "sudoku_traits.h"
#include <iostream>

namespace SudokuHelper {

    bool Data::compare(const SudokuTraits::SudokuMatrix& grid, const SudokuTraits::SudokuMatrix& expected)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if(grid[i][j] != expected[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    };

    void print(const SudokuTraits::SudokuMatrix& arr)
    {
        for (int i = 0; i < N; i++)
        {
            std::cout << "{";
            for (int j = 0; j < N; j++)
                std::cout << arr[i][j] << ", ";
            std::cout << "},";
            std::cout << std::endl;
        }
    }

}
