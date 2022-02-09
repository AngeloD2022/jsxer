#include "RootNode.h"

void RootNode::parse() {
    child = decoders::d_node(reader);
}

string RootNode::jsx() {
    return child->jsx();
}