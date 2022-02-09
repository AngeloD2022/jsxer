#include "ArrayExpr.h"

void ArrayExpr::parse() {
    argumentList = (ArgumentList *) decoders::d_node(reader);
}

string ArrayExpr::to_string() {
    if (!argumentList) {
        return "[]";
    }

    return '[' + argumentList->to_string() + ']';
}