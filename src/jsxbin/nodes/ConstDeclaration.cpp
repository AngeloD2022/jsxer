#include "ConstDeclaration.h"

void ConstDeclaration::parse() {
    name = decoders::d_sid(reader);
    length = decoders::d_length(reader);
    expression = decoders::d_node(reader);
    literal = decoders::d_variant(reader);
    boolean_1 = decoders::d_bool(reader);
    boolean_2 = decoders::d_bool(reader);
}

string ConstDeclaration::to_string() {
    return "const " + name + " = "
    + (expression == nullptr ? literal : expression->to_string());
}
