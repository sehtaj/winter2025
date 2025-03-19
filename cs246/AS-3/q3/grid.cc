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
}

void Grid::turnOn(int i, int j) {
    int n = theGrid.size();
    if (i >= 0 && i < n && j >= 0 && j < n) {
        theGrid[i][j].setLiving();
    }
}

void Grid::tick() {
    for (auto &row : theGrid) {
        for (auto &cell : row) {
            cell.alertNeighbours();
        }
    }

    for (auto &row : theGrid) {
        for (auto &cell : row) {
            cell.recalculate();
        }
    }
}

ostream &operator<<(ostream &out, const Grid &g) {
    int n = g.theGrid.size();
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            out << g.theGrid[row][col];
        }
        out << endl;
    }
    return out;
}