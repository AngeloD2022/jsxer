#include "UnaryExpr.h"

#include <typeinfo>

void UnaryExpr::parse() {
    op = decoders::d_sid(reader);
    expression = decoders::d_node(reader);
}

string UnaryExpr::to_string() {
    bool parenthesis = (!strcmp(typeid(expression).name(), "IdNode"))
            && (!strcmp(typeid(expression).name(), "IdRefExpr"))
            && (!strcmp(typeid(expression).name(), "FunctionCallExpr"))
            && (!strcmp(typeid(expression).name(), "MemberExpr"))
            && (!strcmp(typeid(expression).name(), "ArrayIndexingExpr"));

    return op + (parenthesis ? '(' + expression->to_string() + ')' : expression->to_string());
}
