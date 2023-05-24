#include "ArrayExpression.h"

namespace jsxer::nodes {
    void ArrayExpression::parse() {
        AstNode::parse();

        argumentList = std::dynamic_pointer_cast<ListExpression>(decoders::d_node(reader));
    }

    string ArrayExpression::to_string() {
        if (!argumentList) {
            return "[]";
        }

        return '[' + argumentList->to_string() + ']';
    }
}
