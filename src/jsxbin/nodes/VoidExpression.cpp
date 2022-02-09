#include "VoidExpression.h"

void VoidExpression::parse() {
    expression = decoders::d_node(reader);
}

string VoidExpression::to_string() {
    return expression->to_string();
}
