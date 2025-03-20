#include "a3q1.h"


class IntExpr : public Expr {
    int value;
public:
    IntExpr(int value);
    int evaluate() override;
    string prettyprint() override;
    void set(string var, int value) override;
    void unset(string var) override;
};
