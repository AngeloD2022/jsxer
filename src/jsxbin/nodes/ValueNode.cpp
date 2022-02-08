#include "ValueNode.h"

void ValueNode::parse() {
    value = decoders::d_variant(scanState);
}

string ValueNode::jsx() {
    return value;
}
