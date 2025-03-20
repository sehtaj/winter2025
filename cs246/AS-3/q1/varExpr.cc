#include "varExpr.h"
#include "a3q1.h"



// VarExpr class
VarExpr::VarExpr(string name) : name(name), isSet(false), value(0) {}

int VarExpr::evaluate() {
    bool evaluationError = false;

    if (!isSet) {
        cerr << name << " has no value." << endl;
        evaluationError = true;
        return 0; 
    }
    if (evaluationError) {
        return 0;
    }
    return value;
}

string VarExpr::prettyprint() {
    if (isSet) {
        return to_string(value);
    }
    return name;
}

void VarExpr::set(string var, int val) {
    if (name == var) {
        value = val;
        isSet = true;
    }
}

void VarExpr::unset(string var) {
    if (name == var) {
        isSet = false;
    }
}