#include "ArrayExpression.h"

void ArrayExpression::parse() {
    argumentList = std::static_pointer_cast<ListExpression>(decoders::d_node(reader));
}

string ArrayExpression::to_string() {
    if (!argumentList) {
        return "[]";
    }

    return '[' + argumentList->to_string() + ']';
}