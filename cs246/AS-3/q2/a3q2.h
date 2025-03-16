#ifndef A4Q2_H
#define A4Q2_H

#include <iostream>
#include <stack>
#include <string>
#include <stdexcept>

using namespace std;

class Expr {
public:
    virtual ~Expr() {}
    virtual int evaluate() = 0;
    virtual string prettyprint() = 0;
    virtual void set(string var, int value) = 0;
    virtual void unset(string var) = 0;
    virtual Expr* copy() const = 0;  
};

class IntExpr : public Expr {
    int value;
public:
    IntExpr(int value);
    int evaluate() override;
    string prettyprint() override;
    void set(string var, int value) override;
    void unset(string var) override;
    Expr* copy() const override;  
};

class VarExpr : public Expr {
    string name;
    bool isSet;
    int value;
public:
    VarExpr(string name);
    int evaluate() override;
    string prettyprint() override;
    void set(string var, int value) override;
    void unset(string var) override;
    Expr* copy() const override;  
};

class UnaryExpr : public Expr {
    string op;
    Expr* operand;
public:
    UnaryExpr(string op, Expr* operand);
    ~UnaryExpr();
    int evaluate() override;
    string prettyprint() override;
    void set(string var, int value) override;
    void unset(string var) override;
    Expr* copy() const override;  
};

class BinaryExpr : public Expr {
    string op;
    Expr* left;
    Expr* right;
public:
    BinaryExpr(string op, Expr* left, Expr* right);
    ~BinaryExpr();
    int evaluate() override;
    string prettyprint() override;
    void set(string var, int value) override;
    void unset(string var) override;
    Expr* copy() const override;  
};

void copyCommand(Expr* expr);

istream &operator>>(istream &in, Expr *&e);

#endif 
