#include "ArrayIndexingExpr.h"

void ArrayIndexingExpr::parse() {
    decoders::d_ref(reader); // <str, bool>
    AstNode *name = decoders::d_node(reader);
    AstNode *expr = decoders::d_node(reader);

    arrayName = name->jsx();
    expression = expr->jsx();
}

string ArrayIndexingExpr::jsx() {
    return arrayName + '[' + expression + ']';
}