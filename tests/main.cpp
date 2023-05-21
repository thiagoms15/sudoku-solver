#include <gtest/gtest.h>

#include "isolver.h"
#include "simple.h"
#include "backtracking.h"
#include "sudoku_traits.h"


TEST(test_solve_by_different_methods, test_solve_by_simple_method)
{
    SudokuHelper::Data data;
    SimpleSolver simpleSolver;
    simpleSolver.solve(data.grid);
    EXPECT_TRUE(data.compare());
}

TEST(test_solve_by_different_methods, test_solve_by_backtracing_method)
{
    SudokuHelper::Data data;
    BtSolver btSolver;
    btSolver.solve(data.grid);
    EXPECT_TRUE(data.compare());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

