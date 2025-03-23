#include "grid.h"
#include "cell.h"
#include <iostream>
#include "window.h"  // Added for graphical support

using namespace std;

Grid::Grid() : gridSize(0), window(nullptr) {}

Grid::~Grid() {
    clearGrid();
}

void Grid::clearGrid() {
    theGrid.clear();
    gridSize = 0;
    delete window;  
    window = nullptr;
}

void Grid::init(int n, Xwindow *w) {
    clearGrid();
    gridSize = n;
    window = w;  

    int cellSize = 500 / gridSize;

    theGrid.resize(n, vector<Cell>(n));

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            theGrid[r][c].setCoords(c * cellSize, r * cellSize, cellSize, cellSize, window);  

            if (r > 0) {
                theGrid[r][c].addNeighbour(&theGrid[r - 1][c]);  
            }    
            if (r < n - 1) {
                theGrid[r][c].addNeighbour(&theGrid[r + 1][c]);  
            }
            if (c > 0) {
                theGrid[r][c].addNeighbour(&theGrid[r][c - 1]);
            }
            if (c < n - 1) {
                theGrid[r][c].addNeighbour(&theGrid[r][c + 1]);   
            }
            if (r > 0 && c > 0) {
                theGrid[r][c].addNeighbour(&theGrid[r - 1][c - 1]);   
            }
            if (r > 0 && c < n - 1) {
                theGrid[r][c].addNeighbour(&theGrid[r - 1][c + 1]);
            }
            if (r < n - 1 && c > 0) {
                theGrid[r][c].addNeighbour(&theGrid[r + 1][c - 1]); 
            }
            if (r < n - 1 && c < n - 1) {
                theGrid[r][c].addNeighbour(&theGrid[r + 1][c + 1]); 
            }
        }
    }
}

void Grid::turnOn(int r, int c) {
    if (r >= 0 && r < gridSize && c >= 0 && c < gridSize) {
        theGrid[r][c].setLiving();  
        theGrid[r][c].draw();     
    }
}

void Grid::tick() {
    for (int r = 0; r < gridSize; ++r) {
        for (int c = 0; c < gridSize; ++c) {
            theGrid[r][c].alertNeighbours();  
        }
    }

    for (int r = 0; r < gridSize; ++r) {
        for (int c = 0; c < gridSize; ++c) {
            bool wasAlive = theGrid[r][c].isAlive;  
            theGrid[r][c].recalculate();  

            if (wasAlive && !theGrid[r][c].isAlive) {
                theGrid[r][c].undraw(); 
            } else if (!wasAlive && theGrid[r][c].isAlive) {
                theGrid[r][c].draw(); 
            }
        }
    }
}

void Grid::print() const {
    for (int r = 0; r < gridSize; ++r) {
        for (int c = 0; c < gridSize; ++c) {
            cout << theGrid[r][c];
        }
        cout << endl;
    }
}

ostream &operator<<(ostream &out, const Grid &g) {
    g.print();
    return out;
}