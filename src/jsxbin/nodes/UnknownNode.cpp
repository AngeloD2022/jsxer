#include "UnknownNode.h"

void UnknownNode::parse() {
    id = decoders::d_sid(reader);
    node = decoders::d_node(reader);
}

string UnknownNode::to_string() {
    return "<< DECOMPILER: NO SYNTAX CORRESPONDENCE >>";
}
