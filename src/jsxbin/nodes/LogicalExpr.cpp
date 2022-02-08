#include "LogicalExpr.h"

string get_expr(AbstractNode *node, const string& literal){
    return node == nullptr ? literal : node->jsx();
}

void LogicalExpr::parse() {
    opName = decoders::d_ident(scanState);
    leftExpr = decoders::d_node(scanState);
    rightExpr = decoders::d_node(scanState);
    leftLiteral = decoders::d_variant(scanState);
    rightLiteral = decoders::d_variant(scanState);
}

string LogicalExpr::jsx() {
    return get_expr(leftExpr, leftLiteral) + ' ' + opName + ' ' + get_expr(rightExpr, rightLiteral);
}
