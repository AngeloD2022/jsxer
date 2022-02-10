#include "UnaryRefExpression.h"

void UnaryRefExpression::parse() {
    name = decoders::d_sid(reader);
    argument = decoders::d_node(reader);
}

string UnaryRefExpression::to_string() {
    return name + ' ' + argument->to_string();
}
