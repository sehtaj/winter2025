#include "binaryExpr.h"
#include "a3q1.h"

// BinaryExpr class
BinaryExpr::BinaryExpr(string op, Expr *left, Expr *right) : op(op), left(left), right(right) {}

BinaryExpr::~BinaryExpr() {
    delete left;
    delete right;
}

int BinaryExpr::evaluate() {
    int leftVal = left->evaluate();
    int rightVal = right->evaluate();

    if (op == "+") {
        return leftVal + rightVal;
    } else if (op == "-") {
        return leftVal - rightVal;
    } else if (op == "*") {
        return leftVal * rightVal;
    } else if (op == "/") {
        if (rightVal == 0) {
            cerr << "Division by zero." << endl;
            return 0;
        }
        return leftVal / rightVal;
    }
    return 0;
}

string BinaryExpr::prettyprint() {
    return "(" + left->prettyprint() + " " + op + " " + right->prettyprint() + ")";
}

void BinaryExpr::set(string var, int value) {
    left->set(var, value);
    right->set(var, value);
}

void BinaryExpr::unset(string var) {
    left->unset(var);
    right->unset(var);
}