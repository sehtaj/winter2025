#include "grid.h"
#include "cell.h"
#include <iostream>
#include <vector>

using namespace std;

Grid::Grid() {}

Grid::~Grid() {
    clearGrid();
}

void Grid::clearGrid() {
    theGrid.clear();
}

void Grid::init(int n) {
    clearGrid();

    theGrid.resize(n, std::vector<Cell>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {

            if (i == 0 && j == 0) {
                theGrid[i][j].addNeighbour(&theGrid[0][1]);
                theGrid[i][j].addNeighbour(&theGrid[1][0]);
                theGrid[i][j].addNeighbour(&theGrid[1][1]);
            }

            else if (i == 0 && j == n - 1) {
                theGrid[i][j].addNeighbour(&theGrid[0][n - 2]);
                theGrid[i][j].addNeighbour(&theGrid[1][n - 1]);
                theGrid[i][j].addNeighbour(&theGrid[1][n - 2]);
            }

            else if (i == n - 1 && j == 0) {
                theGrid[i][j].addNeighbour(&theGrid[n - 2][0]);
                theGrid[i][j].addNeighbour(&theGrid[n - 1][1]);
                theGrid[i][j].addNeighbour(&theGrid[n - 2][1]);
            }

            else if (i == n - 1 && j == n - 1) {
                theGrid[i][j].addNeighbour(&theGrid[n - 2][n - 1]);
                theGrid[i][j].addNeighbour(&theGrid[n - 1][n - 2]);
                theGrid[i][j].addNeighbour(&theGrid[n - 2][n - 2]);
            }

            else if (i == 0) {
                theGrid[i][j].addNeighbour(&theGrid[0][j - 1]);
                theGrid[i][j].addNeighbour(&theGrid[0][j + 1]);
                theGrid[i][j].addNeighbour(&theGrid[1][j - 1]);
                theGrid[i][j].addNeighbour(&theGrid[1][j]);
                theGrid[i][j].addNeighbour(&theGrid[1][j + 1]);
            }

            else if (i == n - 1) {
                theGrid[i][j].addNeighbour(&theGrid[n - 1][j - 1]);
                theGrid[i][j].addNeighbour(&theGrid[n - 1][j + 1]);
                theGrid[i][j].addNeighbour(&theGrid[n - 2][j - 1]);
                theGrid[i][j].addNeighbour(&theGrid[n - 2][j]);
                theGrid[i][j].addNeighbour(&theGrid[n - 2][j + 1]);
            }

            else if (j == 0) {
                theGrid[i][j].addNeighbour(&theGrid[i - 1][0]);
                theGrid[i][j].addNeighbour(&theGrid[i + 1][0]);
                theGrid[i][j].addNeighbour(&theGrid[i - 1][1]);
                theGrid[i][j].addNeighbour(&theGrid[i][1]);
                theGrid[i][j].addNeighbour(&theGrid[i + 1][1]);
            }

            else if (j == n - 1) {
                theGrid[i][j].addNeighbour(&theGrid[i - 1][n - 1]);
                theGrid[i][j].addNeighbour(&theGrid[i + 1][n - 1]);
                theGrid[i][j].addNeighbour(&theGrid[i - 1][n - 2]);
                theGrid[i][j].addNeighbour(&theGrid[i][n - 2]);
                theGrid[i][j].addNeighbour(&theGrid[i + 1][n - 2]);
            }

            else {
                theGrid[i][j].addNeighbour(&theGrid[i - 1][j - 1]);
                theGrid[i][j].addNeighbour(&theGrid[i - 1][j]);
                theGrid[i][j].addNeighbour(&theGrid[i - 1][j + 1]);
                theGrid[i][j].addNeighbour(&theGrid[i][j - 1]);
                theGrid[i][j].addNeighbour(&theGrid[i][j + 1]);
                theGrid[i][j].addNeighbour(&theGrid[i + 1][j - 1]);
                theGrid[i][j].addNeighbour(&theGrid[i + 1][j]);
                theGrid[i][j].addNeighbour(&theGrid[i + 1][j + 1]);
            }
        }
    }
}

void Grid::turnOn(int i, int j) {
    int n = theGrid.size();
    if (i >= 0 && i < n && j >= 0 && j < n) {
        theGrid[i][j].setLiving();
    }
}

void Grid::tick() {
    for (auto &i : theGrid) {
        for (auto &cell : i) {
            cell.alertNeighbours();
        }
    }
    for (auto &i : theGrid) {
        for (auto &cell : i) {
            cell.recalculate();
        }
    }
}

ostream &operator<<(ostream &out, const Grid &g) {
    int n = g.theGrid.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            out << g.theGrid[i][j];
        }
        out << endl;
    }
    return out;
}