#ifndef __GRID_H__
#define __GRID_H__
#include <iostream>
#include <vector>
#include "cell.h"

using namespace std;

class Grid {
  int gridSize;
  vector<vector<Cell>> theGrid;  // The actual grid.
  Xwindow *window;


  // Add private members, if necessary.

  void clearGrid();   // Frees the grid.

 public:
  Grid();
  ~Grid();

  void init(int n, Xwindow *w = nullptr); // Sets up an n x n grid.  Clears old grid, if necessary.
                    // Initializes every cell in the grid, and tells each
                    // cell who its neighbours are.

  void tick();      // Runs one iteration of the simulation.
                    // Tells each cell to alert its neighbours, and then
                    // tells each cell to recalculate.

  void turnOn(int i, int j); // Sets cell at i, j to living.

    void print() const;
  

  friend ostream& operator<<(ostream &out, const Grid &g);
};

#endif
