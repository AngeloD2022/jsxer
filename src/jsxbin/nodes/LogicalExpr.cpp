#include "LogicalExpr.h"

string get_expr(AstNode *node, const string& literal){
    return node == nullptr ? literal : node->jsx();
}

void LogicalExpr::parse() {
    opName = decoders::d_ident(reader);
    leftExpr = decoders::d_node(reader);
    rightExpr = decoders::d_node(reader);
    leftLiteral = decoders::d_variant(reader);
    rightLiteral = decoders::d_variant(reader);
}

string LogicalExpr::jsx() {
    return get_expr(leftExpr, leftLiteral) + ' ' + opName + ' ' + get_expr(rightExpr, rightLiteral);
}
