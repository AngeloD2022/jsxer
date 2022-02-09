#include "XMLDoubleDotDescendantsExpr.h"

void XMLDoubleDotDescendantsExpr::parse() {
    descendants = decoders::d_ref(reader);
    object = decoders::d_node(reader);

    decoders::d_node(reader);
    decoders::d_node(reader);
}

string XMLDoubleDotDescendantsExpr::jsx() {
    return object->jsx() + ".." + descendants.id;
}
