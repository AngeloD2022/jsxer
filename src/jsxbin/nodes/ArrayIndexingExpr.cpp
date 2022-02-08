#include "ArrayIndexingExpr.h"

void ArrayIndexingExpr::parse() {
    decoders::d_ref(scanState); // <str, bool>
    AbstractNode *name = decoders::d_node(scanState);
    AbstractNode *expr = decoders::d_node(scanState);

    arrayName = name->jsx();
    expression = expr->jsx();
}

string ArrayIndexingExpr::jsx() {
    return arrayName + '[' + expression + ']';
}