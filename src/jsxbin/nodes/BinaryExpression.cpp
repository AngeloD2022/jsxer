#include "BinaryExpression.h"

using namespace jsxbin::nodes;

string BinaryExpression::create_expr(const string& literal, AstNode* exprNode) {
    bool parenthesis = false;
    string expression;

    if (exprNode != nullptr && (exprNode->type() == NodeType::BinaryExpression)) {
        auto* binExpr = (BinaryExpression *) exprNode;
        expression = binExpr->get_op();

        bool associative = (strcmp(binExpr->get_op_name().c_str(), "*") == 0
                            && strcmp(op_name.c_str(), "*") == 0) ||
                                    (strcmp(binExpr->get_op_name().c_str(), "+") == 0
                                    && strcmp(op_name.c_str(), "+") == 0);

        parenthesis = !associative;
    } else {
        expression = exprNode == nullptr ? literal : exprNode->to_string();
    }

    return parenthesis ? "(" + expression + ")" : expression;
}

void BinaryExpression::parse() {
    op_name = decoders::d_sid(reader);
    left = decoders::d_node(reader);
    right = decoders::d_node(reader);
    literalLeft = decoders::d_variant(reader);
    literalRight = decoders::d_variant(reader);

    string leftExp = create_expr(literalLeft, left);
    string rightExp = create_expr(literalRight, right);

    if ((!leftExp.empty() && rightExp.empty()) || (leftExp.empty() && !rightExp.empty())) {
        op = leftExp + rightExp;
    } else {
        op = leftExp + ' ' + op_name + ' ' + rightExp;
    }
}

string BinaryExpression::to_string() {
    return op;
}
