#include "XMLPredicateExpression.h"

namespace jsxer::nodes {
    void XMLPredicateExpression::parse() {
        reference = decoders::d_literal_ref(reader);
        object = decoders::d_node(reader);
        member = decoders::d_node(reader);
    }

    string XMLPredicateExpression::to_string() {

        bool parenthesis = member->type() == NodeType::BinaryExpression
                           || member->type() == NodeType::LogicalExpression
                           || member->type() == NodeType::UnaryExpression;

        return object->to_string() + '.'
               + (parenthesis ? '(' + member->to_string() + ')' : member->to_string());
    }
}
