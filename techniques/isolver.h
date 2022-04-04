#ifndef __ISOLVER__
#define __ISOLVER__

// N is the size of the 2D matrix N*N
const int N = 9;

// UNASSIGNED is used for empty
// cells in sudoku grid
#define UNASSIGNED 0

class ISolver
{
	public:
		ISolver() = default;
		~ISolver() = default;
		virtual bool solve(int arr[N][N]) = 0;
};
#endif
