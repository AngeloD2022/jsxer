#include "IndexingExpression.h"

void IndexingExpression::parse() {
    auto ref = decoders::d_ref(reader); // <str, bool>
    shared_ptr<AstNode> name = decoders::d_node(reader);
    shared_ptr<AstNode> expr = decoders::d_node(reader);

    arrayName = name->to_string();
    expression = expr->to_string();
}

string IndexingExpression::to_string() {
    return arrayName + '[' + expression + ']';
}