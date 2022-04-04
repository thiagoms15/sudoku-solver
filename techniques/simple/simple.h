#ifndef __SIMPLE__
#define __SIMPLE__

#include "isolver.h"

class SimpleSolver : public ISolver
{
	public:
		SimpleSolver();
		~SimpleSolver();
		bool solve(int arr[N][N]) override;

	private:
		bool isSafe(int grid[N][N], int row, int col, int num);
		bool solveSuduko(int grid[N][N], int row, int col);

};
#endif
