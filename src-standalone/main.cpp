#include "isolver.h"
#include "sudoku_traits.h"
#include "simple.h"
#include "backtracking.h"

#include <iostream>
#include <vector>


int main(int argc, char **argv)
{

    SudokuHelper::Data data;
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

    mySolverMethodVector[option]->solve(data.grid);
    if(data.compare())
    {
        std::cout << "Solve with success" << std::endl;
    }

    return 0;
}

