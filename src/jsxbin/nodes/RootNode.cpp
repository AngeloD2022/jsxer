#include "RootNode.h"

void RootNode::parse() {
    child = decoders::d_node(scanState);
}

string RootNode::jsx() {
    return child->jsx();
}