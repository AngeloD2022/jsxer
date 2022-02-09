#include "ArrayExpression.h"

void ArrayExpression::parse() {
    argumentList = (ListExpression*) decoders::d_node(reader);
}

string ArrayExpression::to_string() {
    if (!argumentList) {
        return "[]";
    }

    return '[' + argumentList->to_string() + ']';
}