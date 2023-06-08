#include <iostream>
#include "getApi.h"

int main(void)
{
    GetApi getApi("https://sudoku-api.vercel.app/api/dosuku");
//    GetApi getApi("https://sugoku.onrender.com/board\?difficulty\=easy");

    std::cout << "msg = " << getApi.chunk.memory << std::endl;

    return 0;
}
