#include <iostream>
#include <sstream>
#include <string>
#include "a3q2.h"

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
            cout << result << endl;
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
        } else if (s == "copy") { 
            Expr *theCopy = e->copy();
            cout << theCopy->prettyprint() << endl;
            theCopy->set("x", 1);
            cout << theCopy->prettyprint() << endl;
            try {
                cout << theCopy->evaluate() << endl;
            } catch (const exception &ex) {
                cerr << ex.what() << endl;
            }
            delete theCopy;
        } else {
            cout << "Unknown command: " << s << endl;
        }
    }

    delete e;
    return 0;
}
