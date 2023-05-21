#ifndef __BACKTRAKING__
#define __BACKTRAKING__

#include "isolver.h"

class BtSolver : public ISolver
{
    public:

        /* Takes a partially filled-in grid and attempts
           to assign values to all unassigned locations in
           such a way to meet the requirements for
           Sudoku solution (non-duplication across rows,
           columns, and boxes) */
        bool solve(SudokuTraits::SudokuMatrix&) override;

    private:
        /* Searches the grid to find an entry that is
           still unassigned. If found, the reference
           parameters row, col will be set the location
           that is unassigned, and true is returned.
           If no unassigned entries remain, false is returned. */
        bool FindUnassignedLocation(SudokuTraits::SudokuMatrix& grid,
                int& row, int& col);

        /* Returns a boolean which indicates whether
           an assigned entry in the specified row matches
           the given number. */
        bool UsedInRow(SudokuTraits::SudokuMatrix& grid, int row, int num);

        /* Returns a boolean which indicates whether
           an assigned entry in the specified column
           matches the given number. */
        bool UsedInCol(SudokuTraits::SudokuMatrix& grid, int col, int num);

        /* Returns a boolean which indicates whether
           an assigned entry within the specified 3x3 box
           matches the given number. */
        bool UsedInBox(SudokuTraits::SudokuMatrix& grid, int boxStartRow,
                int boxStartCol, int num);

        /* Returns a boolean which indicates whether
           it will be legal to assign num to the given
           row, col location. */
        bool isSafe(SudokuTraits::SudokuMatrix& grid, int row,
                int col, int num);
};

#endif

