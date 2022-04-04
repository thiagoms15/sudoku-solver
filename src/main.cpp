#include "isolver.h"
#include "simple.h"
#include "backtracking.h"

#include <iostream>
#include <vector>


bool compare(const int (&grid)[N][N], const int (&expected)[N][N])
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
}


int main(int argc, char **argv)
{
	// 0 means unassigned cells
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
        { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
        { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
        { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
        { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
        { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
        { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    int expected[N][N] = { {3, 1, 6, 5, 7, 8, 4, 9, 2 },
        {5, 2, 9, 1, 3, 4, 7, 6, 8 },
        {4, 8, 7, 6, 2, 9, 5, 3, 1 },
        {2, 6, 3, 4, 1, 5, 9, 8, 7 },
        {9, 7, 4, 8, 6, 3, 1, 2, 5 },
        {8, 5, 1, 7, 9, 2, 6, 4, 3 },
        {1, 3, 8, 9, 4, 7, 2, 5, 6 },
        {6, 9, 2, 3, 5, 1, 8, 7, 4 },
        {7, 4, 5, 2, 8, 6, 3, 1, 9 } };


    std::vector<ISolver*> mySolverMethodVector;
    SimpleSolver simpleSolver;
    BtSolver btSolver;

    mySolverMethodVector.push_back(&simpleSolver);
    mySolverMethodVector.push_back(&btSolver);

    int option = 0;
    do
    {
        std::cout << "Choose a method to solve the Sudoku\n";
        std::cout << "[0] - Simple\n";
        std::cout << "[1] - Backtracing\n";

        std::cout << "Option: ";
        std::cin >> option;
    }
    while ((option != 0) && (option !=1));

    mySolverMethodVector[option]->solve(grid);
    if(compare(grid, expected))
    {
        std::cout << "Solve with success" << std::endl;
    }

    return 0;
}
