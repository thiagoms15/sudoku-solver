// A Backtracking program in
// C++ to solve Sudoku problem
#include <bits/stdc++.h>
#include "backtracking.h"

/* Takes a partially filled-in grid and attempts
to assign values to all unassigned locations in
such a way to meet the requirements for
Sudoku solution (non-duplication across rows,
columns, and boxes) */
bool BtSolver::solve(SudokuTraits::SudokuMatrix& grid)
{
	int row, col;

	// If there is no unassigned location,
	// we are done
	if (!FindUnassignedLocation(grid, row, col))
		// success!
		return true;

	// Consider digits 1 to 9
	for (int num = 1; num <= 9; num++)
	{

		// Check if looks promising
		if (isSafe(grid, row, col, num))
		{

			// Make tentative assignment
			grid[row][col] = num;

			// Return, if success
			if (solve(grid))
				return true;

			// Failure, unmake & try again
			grid[row][col] = UNASSIGNED;
		}
	}

	// This triggers backtracking
	return false;
}

/* Searches the grid to find an entry that is
still unassigned. If found, the reference
parameters row, col will be set the location
that is unassigned, and true is returned.
If no unassigned entries remain, false is returned. */
bool BtSolver::FindUnassignedLocation(SudokuTraits::SudokuMatrix& grid,
							int& row, int& col)
{
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (grid[row][col] == UNASSIGNED)
				return true;
	return false;
}

/* Returns a boolean which indicates whether
an assigned entry in the specified row matches
the given number. */
bool BtSolver::UsedInRow(SudokuTraits::SudokuMatrix& grid, int row, int num)
{
	for (int col = 0; col < N; col++)
		if (grid[row][col] == num)
			return true;
	return false;
}

/* Returns a boolean which indicates whether
an assigned entry in the specified column
matches the given number. */
bool BtSolver::UsedInCol(SudokuTraits::SudokuMatrix& grid, int col, int num)
{
	for (int row = 0; row < N; row++)
		if (grid[row][col] == num)
			return true;
	return false;
}

/* Returns a boolean which indicates whether
an assigned entry within the specified 3x3 box
matches the given number. */
bool BtSolver::UsedInBox(SudokuTraits::SudokuMatrix& grid, int boxStartRow,
			int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (grid[row + boxStartRow]
					[col + boxStartCol] ==
									num)
				return true;
	return false;
}

/* Returns a boolean which indicates whether
it will be legal to assign num to the given
row, col location. */
bool BtSolver::isSafe(SudokuTraits::SudokuMatrix& grid, int row,
			int col, int num)
{
	/* Check if 'num' is not already placed in
	current row, current column
	and current 3x3 box */
	return !UsedInRow(grid, row, num)
		&& !UsedInCol(grid, col, num)
		&& !UsedInBox(grid, row - row % 3,
						col - col % 3, num)
		&& grid[row][col] == UNASSIGNED;
}

