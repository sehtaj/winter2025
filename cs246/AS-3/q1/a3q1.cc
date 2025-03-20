#include "intExpr.h"
#include "varExpr.h"
#include "unaryExpr.h"
#include "binaryExpr.h"

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
        }
        else if (isalpha(s[0])) {
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
        }
        else if (s == "+" || s == "-" || s == "*" || s == "/") {
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