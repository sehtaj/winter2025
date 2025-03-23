#include "cell.h"

Cell::Cell() : isAlive(false), numNeighbours(0), aliveNeighbours(0) {
    for (int i = 0; i < maxNeighbours; ++i) {
        neighbours[i] = nullptr;
    }
}

Cell::~Cell() {}

void Cell::setLiving() {
    isAlive = true;
}

void Cell::addNeighbour(Cell *neighbour) {
    if (numNeighbours < maxNeighbours) {
        neighbours[numNeighbours++] = neighbour;
    }
}

void Cell::neighbourIsAlive() {
    aliveNeighbours++;
}

void Cell::alertNeighbours() {
    if (isAlive) {
        for (int i = 0; i < numNeighbours; ++i) {
            if (neighbours[i]) {
                neighbours[i]->neighbourIsAlive();
            }
        }
    }
}

void Cell::recalculate() {
    if (isAlive) {
        if (aliveNeighbours < 2 || aliveNeighbours > 3) {
            isAlive = false;
        }
    } else {
        if (aliveNeighbours == 3) {
            isAlive = true;
        }
    }
    aliveNeighbours = 0;
}

void Cell::setCoords(int x, int y, int width, int height, Xwindow *w) {
    xCoord = x;
    yCoord = y;
    width = width;
    height = height;
    window = w;
}

void Cell::draw() {
    if (window) {
        window->fillRectangle(xCoord, yCoord, width, height, Xwindow::Black);
    }
}

void Cell::undraw() {
    if (window) {
        window->fillRectangle(xCoord, yCoord, width, height, Xwindow::White);
    }
}

ostream &operator<<(ostream &out, const Cell &c) {
    if (c.isAlive) {
        out << "X";
    } else {
        out << "_";
    }
    return out;
}

