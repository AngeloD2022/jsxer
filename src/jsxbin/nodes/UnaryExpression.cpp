#include "UnaryExpression.h"

void UnaryExpression::parse() {
    op = decoders::d_sid(reader);
    expression = decoders::d_node(reader);
}

string UnaryExpression::to_string() {
    bool parenthesis = expression->type() != NodeType::Identifier
                       && expression->type() != NodeType::LocalIdentifier
                       && expression->type() != NodeType::CallExpression
                       && expression->type() != NodeType::MemberExpression
                       && expression->type() != NodeType::IndexingExpression;

    return op + (parenthesis ? '(' + expression->to_string() + ')' : expression->to_string());
}
