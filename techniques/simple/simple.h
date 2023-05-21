#ifndef __SIMPLE__
#define __SIMPLE__

#include "isolver.h"

class SimpleSolver : public ISolver
{
	public:
		SimpleSolver() = default;
		~SimpleSolver() = default;
		bool solve(SudokuTraits::SudokuMatrix&) override;

	private:
		bool isSafe(SudokuTraits::SudokuMatrix& grid, int row, int col, int num);
		bool solveSudoku(SudokuTraits::SudokuMatrix& grid, int row, int col);

};
#endif
