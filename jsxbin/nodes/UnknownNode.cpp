//
// Created by Angelo DeLuca on 12/26/21.
//

#include "UnknownNode.h"

void UnknownNode::parse() {
    id = decoders::d_ident(scanState);
    node = decoders::d_node(scanState);
}

string UnknownNode::jsx() {
    return "<< DECOMPILER: NO SYNTAX CORRESPONDENCE >>";
}
