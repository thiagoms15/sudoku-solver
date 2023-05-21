#ifndef __ISOLVER__
#define __ISOLVER__

#include "sudoku_traits.h"

class ISolver
{
	public:
		ISolver() = default;
		~ISolver() = default;
		virtual bool solve(SudokuTraits::SudokuMatrix&) = 0;
};
#endif
