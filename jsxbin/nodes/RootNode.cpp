//
// Created by Angelo DeLuca on 12/30/21.
//

#include "RootNode.h"

void RootNode::parse() {
    child = decoders::d_node(scanState);
}

string RootNode::jsx() {
    return child->jsx();
}