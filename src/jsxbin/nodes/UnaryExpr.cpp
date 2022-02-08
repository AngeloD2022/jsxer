#include "UnaryExpr.h"

void UnaryExpr::parse() {
    op = decoders::d_ident(scanState);
    expression = decoders::d_node(scanState);
}

string UnaryExpr::jsx() {
    bool parenthesis = !(istype(expression, "IdNode"))
            && !(istype(expression, "IdRefExpr"))
            && !(istype(expression, "FunctionCallExpr"))
            && !(istype(expression, "MemberExpr"))
            && !(istype(expression, "ArrayIndexingExpr"));

    return op + (parenthesis ? '(' + expression->jsx() + ')' : expression->jsx());
}
