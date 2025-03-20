#include "intExpr.h"


// IntExpr class
IntExpr::IntExpr(int value) : value(value) {}

int IntExpr::evaluate() {
    return value;
}

string IntExpr::prettyprint() {
    return to_string(value);
}

void IntExpr::set(string var, int value) {}

void IntExpr::unset(string var) {}