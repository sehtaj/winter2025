#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include "window.h"

using namespace std;

const int maxNeighbours = 8;

class Cell {
  bool isAlive;
  int numNeighbours;
  Cell *neighbours[maxNeighbours];
  int aliveNeighbours;

  // Add other private members if necessary

  int xCoord;
  int yCoord;
  int width;
  int height;
  Xwindow *window;

 public:
  Cell();  // Default constructor
  ~Cell(); // Destructor

  void setLiving();         // Explicitly sets me to living.

  void addNeighbour(Cell *neighbour);  // Adds a pointer to one of my
                            // neighbours to my array.

  void neighbourIsAlive();  // My neighbours will call this, to let me know
                            // they're alive.

  void alertNeighbours();   // Tell all of my neighbours that I am alive
                            // (if I'm alive).

  void recalculate();       // Reassess my living-or-dead status, based on
                            // info from neighbours.

  
  void setCoords(int x, int y, int w, int h, Xwindow *win);
  void draw();
  void undraw();
  friend ostream& operator<<(ostream &out, const Cell &c);
  friend class Grid;
};

#endif
