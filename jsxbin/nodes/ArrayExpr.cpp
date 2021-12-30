//
// Created by Angelo DeLuca on 12/30/21.
//

#include "ArrayExpr.h"

void ArrayExpr::parse() {
    argumentList = (ArgumentList *) decoders::d_node(scanState);
}

string ArrayExpr::jsx() {
    if (argumentList == nullptr) {
        return "[]";
    }

    return '[' + argumentList->jsx() + ']';
}