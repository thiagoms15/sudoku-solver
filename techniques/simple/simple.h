#ifndef __SIMPLE__
#define __SIMPLE__

// N is the size of the 2D matrix N*N
const int N = 9;
class SimpleSolver
{
	public:

		SimpleSolver();
		~SimpleSolver();
		bool solve(int arr[N][N]);

	private:

		bool isSafe(int grid[N][N], int row, int col, int num);
		bool solveSuduko(int grid[N][N], int row, int col);

};
#endif
