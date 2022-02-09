#include "IndexingExpression.h"

void IndexingExpression::parse() {
    decoders::d_ref(reader); // <str, bool>
    AstNode *name = decoders::d_node(reader);
    AstNode *expr = decoders::d_node(reader);

    arrayName = name->to_string();
    expression = expr->to_string();
}

string IndexingExpression::to_string() {
    return arrayName + '[' + expression + ']';
}