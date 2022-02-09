#include "UnknownNode.h"

void UnknownNode::parse() {
    id = decoders::d_ident(reader);
    node = decoders::d_node(reader);
}

string UnknownNode::jsx() {
    return "<< DECOMPILER: NO SYNTAX CORRESPONDENCE >>";
}
