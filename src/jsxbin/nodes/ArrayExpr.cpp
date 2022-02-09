#include "ArrayExpr.h"

void ArrayExpr::parse() {
    argumentList = (ArgumentList *) decoders::d_node(reader);
}

string ArrayExpr::jsx() {
    if (!argumentList) {
        return "[]";
    }

    return '[' + argumentList->jsx() + ']';
}