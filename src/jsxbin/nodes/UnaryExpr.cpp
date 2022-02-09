#include "UnaryExpr.h"

void UnaryExpr::parse() {
    op = decoders::d_ident(reader);
    expression = decoders::d_node(reader);
}

string UnaryExpr::jsx() {
    bool parenthesis = !(istype(expression, "IdNode"))
            && !(istype(expression, "IdRefExpr"))
            && !(istype(expression, "FunctionCallExpr"))
            && !(istype(expression, "MemberExpr"))
            && !(istype(expression, "ArrayIndexingExpr"));

    return op + (parenthesis ? '(' + expression->jsx() + ')' : expression->jsx());
}
