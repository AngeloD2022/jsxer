#include "LogicalExpression.h"

string get_expr(AstNode *node, const string& literal){
    return '(' + (node == nullptr ? literal : node->to_string()) + ')';
}

void LogicalExpression::parse() {
    opName = decoders::d_sid(reader);
    leftExpr = decoders::d_node(reader);
    rightExpr = decoders::d_node(reader);
    leftLiteral = decoders::d_variant(reader);
    rightLiteral = decoders::d_variant(reader);
}

string LogicalExpression::to_string() {
    return get_expr(leftExpr, leftLiteral) + ' ' + opName + ' ' + get_expr(rightExpr, rightLiteral);
}
