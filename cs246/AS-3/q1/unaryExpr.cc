#include "unaryExpr.h"
#include "a3q1.h"



// UnaryExpr class
UnaryExpr::UnaryExpr(string op, Expr *operand) : op(op), operand(operand) {}

UnaryExpr::~UnaryExpr() {
    delete operand;
}

int UnaryExpr::evaluate() {
    int val = operand->evaluate();
    if (op == "NEG") {
        return -val;
    } else if (op == "ABS") {
        return val < 0 ? -val : val;
    }
    return 0;
}

string UnaryExpr::prettyprint() {
    if (op == "NEG") {
        return "-" + operand->prettyprint();
    } else if (op == "ABS") {
        return "|" + operand->prettyprint() + "|";
    }
    return "";
}

void UnaryExpr::set(string var, int value) {
    operand->set(var, value);
}

void UnaryExpr::unset(string var) {
    operand->unset(var);
}