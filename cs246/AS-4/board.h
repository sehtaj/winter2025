#ifndef BOARD_H
#define BOARD_H

#include <iostream>
using namespace std;

class Board {
private:
    char board[8][8];  

public:
    Board();  
    void printBoard();  
};

#endif