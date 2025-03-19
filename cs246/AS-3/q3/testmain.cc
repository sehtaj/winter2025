#include "grid.h"
#include "cell.h"
#include <iostream>

using namespace std;

int main() {
    Grid theGrid;

    // Test grid creation
    cout << "New 5x5 grid" << endl;
    theGrid.init(5);
    cout << "Initial empty grid:" << endl;
    cout << theGrid;

    // Test turning on cells
    cout << "Turning on cells at (1, 2), (2, 2), (2, 3)." << endl;
    theGrid.turnOn(1, 2);
    theGrid.turnOn(2, 2);
    theGrid.turnOn(2, 3);
    cout << "After Turning cells" << endl;
    cout << theGrid;

    // Test one step (tick)
    cout << "one tick" << endl;
    theGrid.tick();
    cout << "after one step:" << endl;
    cout << theGrid;

    // Test multiple steps
    cout << "4 steps." << endl;
    for (int i = 0; i < 4; ++i) {
        theGrid.tick();
        cout << "step " << (i + 1) << ":" << endl;
        cout << theGrid;
    }

    return 0;
}