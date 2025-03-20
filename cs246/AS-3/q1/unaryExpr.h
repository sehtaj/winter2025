#include "a3q1.h"

class UnaryExpr : public Expr {
    string op;
    Expr *operand;
public:
    UnaryExpr(string op, Expr *operand);
    ~UnaryExpr();
    int evaluate() override;
    string prettyprint() override;
    void set(string var, int value) override;
    void unset(string var) override;
};