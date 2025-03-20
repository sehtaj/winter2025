#include "a3q1.h"


class BinaryExpr : public Expr {
    string op;
    Expr *left;
    Expr *right;
public:
    BinaryExpr(string op, Expr *left, Expr *right);
    ~BinaryExpr();
    int evaluate() override;
    string prettyprint() override;
    void set(string var, int value) override;
    void unset(string var) override;
};