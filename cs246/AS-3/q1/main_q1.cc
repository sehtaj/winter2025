#include <iostream>
#include <sstream>
#include <string>
#include "a3q1.h"

using namespace std;

// You will need to write your own test harness

// Read and construct expression object. Returns a pointer to a heap-allocated
// object (caller must delete it).

int main() {
    string s;
    Expr *e;

    cin >> e;
    
    // Command interpreter
    while (cin >> s) {
        if (s == "eval") {
            int result = e->evaluate();
            if (e->prettyprint() != "x" || result != 0) {
                cout << result << endl;
            }
        } else if (s == "set") {
            string var;
            int value;
            cin >> var >> value;
            e->set(var, value);
        } else if (s == "unset") {
            string var;
            cin >> var;
            e->unset(var);
        } else if (s == "print") {
            cout << e->prettyprint() << endl;
        } else {
            cout << "Unknown command: " << s << endl;
        }
    }

    delete e;
    return 0;
}