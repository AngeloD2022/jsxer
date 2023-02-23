#include "UnaryExpression.h"

namespace jsxer::nodes {
    void UnaryExpression::parse() {
        op = decoders::d_operator(reader);
        expression = decoders::d_node(reader);
    }

    string UnaryExpression::to_string() {
        bool parenthesis = expression->type() != NodeType::Identifier
                           && expression->type() != NodeType::LocalIdentifier
                           && expression->type() != NodeType::CallExpression
                           && expression->type() != NodeType::MemberExpression
                           && expression->type() != NodeType::IndexingExpression;

    // if plus ("+") is used as a unary operator, simply ignore it.
    if (op != "+")
        return op + (parenthesis ? '(' + expression->to_string() + ')' : expression->to_string());
    else
        return (parenthesis ? '(' + expression->to_string() + ')' : expression->to_string());
    }
}
