#include "ArrayExpression.h"

namespace jsxer::nodes {
    void ArrayExpression::parse() {
        print_tree_node(reader, "ArrayExpression");

        argumentList = std::dynamic_pointer_cast<ListExpression>(decoders::d_node(reader));
    }

    string ArrayExpression::to_string() {
        if (!argumentList) {
            return "[]";
        }

        return '[' + argumentList->to_string() + ']';
    }
}
