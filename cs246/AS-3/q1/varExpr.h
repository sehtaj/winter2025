#include "a3q1.h"

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
};