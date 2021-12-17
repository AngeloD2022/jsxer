//
// Created by Angelo DeLuca on 12/16/21.
//

#include "ConstDeclaration.h"

void ConstDeclaration::parse() {
    name = decoders::d_ident(scanState);
    length = decoders::d_length(scanState);
    expression = decoders::d_node(scanState);
    literal = decoders::d_variant(scanState);
    boolean_1 = decoders::d_bool(scanState);
    boolean_2 = decoders::d_bool(scanState);
}

string ConstDeclaration::jsx() {
    return "const " + name + " = "
    + (expression == nullptr ? literal : expression->jsx());
}
