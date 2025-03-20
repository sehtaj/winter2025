#ifndef A4Q1_H
#define A4Q1_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <stack>

using namespace std;

class Expr {
public:
    virtual ~Expr() {}
    virtual int evaluate() = 0;
    virtual string prettyprint() = 0;
    virtual void set(string var, int value) = 0;
    virtual void unset(string var) = 0;
};

istream &operator>>(istream &in, Expr *&e);

#endif