#include "ValueNode.h"

void ValueNode::parse() {
    value = decoders::d_variant(reader);
}

string ValueNode::jsx() {
    return value;
}
