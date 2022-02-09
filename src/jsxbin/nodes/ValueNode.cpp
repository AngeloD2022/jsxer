#include "ValueNode.h"

void ValueNode::parse() {
    value = decoders::d_variant(reader);
}

string ValueNode::to_string() {
    return value;
}
