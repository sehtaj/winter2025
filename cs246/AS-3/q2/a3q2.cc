#include "a3q2.h"


// IntExpr class
IntExpr::IntExpr(int value) : value(value) {}

int IntExpr::evaluate() {
    return value;
}

string IntExpr::prettyprint() {
    return to_string(value);
}

void IntExpr::set(string var, int value) { 
    (void)var; 
    (void)value;
}

void IntExpr::unset(string var) { 
    (void)var; 
}

Expr* IntExpr::copy() const {
    return new IntExpr(value);
}

// VarExpr class
VarExpr::VarExpr(string name) : name(name), isSet(false), value(0) {}

int VarExpr::evaluate() {
    if (!isSet) {
        cerr << name << " has no value." << endl;
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

Expr* VarExpr::copy() const {
    VarExpr* newVar = new VarExpr(name);
    newVar->isSet = isSet;
    newVar->value = value;
    return newVar;
}

// UnaryExpr class
UnaryExpr::UnaryExpr(string op, Expr* operand) : op(op), operand(operand) {}

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

Expr* UnaryExpr::copy() const {
    return new UnaryExpr(op, operand->copy());
}

// BinaryExpr class
BinaryExpr::BinaryExpr(string op, Expr* left, Expr* right) : op(op), left(left), right(right) {}

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

Expr* BinaryExpr::copy() const {
    return new BinaryExpr(op, left->copy(), right->copy());
}

istream &operator>>(istream &in, Expr *&e) {
    stack<Expr *> exprStack;
    string s;

    while (in >> s) {
        if (s == "done") {
            break;
        }

        if (isdigit(s[0]) || (s[0] == '-' && s.size() > 1)) {
            int value = stoi(s);
            exprStack.push(new IntExpr(value));
        } else if (isalpha(s[0])) {
            if (s == "NEG" || s == "ABS") {
                if (exprStack.empty()) {
                    e = nullptr;
                    return in;
                }
                Expr *operand = exprStack.top();
                exprStack.pop();
                exprStack.push(new UnaryExpr(s, operand));
            } else {
                exprStack.push(new VarExpr(s));
            }
        } else if (s == "+" || s == "-" || s == "*" || s == "/") {
            if (exprStack.size() < 2) {
                e = nullptr;
                return in;
            }
            Expr *right = exprStack.top();
            exprStack.pop();
            Expr *left = exprStack.top();
            exprStack.pop();
            exprStack.push(new BinaryExpr(s, left, right));
        } else {
            e = nullptr;
            return in;
        }
    }

    if (exprStack.size() == 1) {
        e = exprStack.top();
    } else {
        e = nullptr;
    }
    return in;
}

void copyCommand(Expr* expr) {
    Expr* theCopy = expr->copy();
    cout << theCopy->prettyprint() << endl;
    theCopy->set("x", 1);
    cout << theCopy->prettyprint() << endl;
    try {
        int result = theCopy->evaluate();
        cout << result << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
    delete theCopy;
}
