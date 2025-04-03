#include <iostream>
#include "board.h"

Board::Board() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ((i + j) % 2 == 0)
                board[i][j] = ' '; 
            else
                board[i][j] = '_';  
        }
    }
}

void Board::printBoard() {
    for (int i = 0; i < 8; ++i) {
        cout << 8 - i << " "; 
        for (int j = 0; j < 8; ++j) {
            cout << board[i][j] << " "; 
        }
        cout << endl;  
    }
    cout << "  a b c d e f g h" << endl; 
}

