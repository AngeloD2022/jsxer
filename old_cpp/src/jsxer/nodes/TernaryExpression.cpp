#include "TernaryExpression.h"


namespace jsxer::nodes {
    bool parenthesis(const AstOpNode& node) {
        return (node->type() == NodeType::TernaryExpression) && (node->type() == NodeType::ListExpression);
    }

    void TernaryExpression::parse() {
        condition = decoders::d_node(reader);
        node_true = decoders::d_node(reader);
        node_false = decoders::d_node(reader);
    }

    string TernaryExpression::to_string() {
        return condition->to_string() + " ? " +
               (parenthesis(node_true) ? '(' + node_true->to_string() + ')' : node_true->to_string())
               + " : "
               + (parenthesis(node_false) ? '(' + node_false->to_string() + ')' : node_false->to_string());
    }
}
