#include "XMLDoubleDotDescendantsExpr.h"

void XMLDoubleDotDescendantsExpr::parse() {
    descendants = decoders::d_ref(scanState);
    object = decoders::d_node(scanState);

    decoders::d_node(scanState);
    decoders::d_node(scanState);
}

string XMLDoubleDotDescendantsExpr::jsx() {
    return object->jsx() + ".." + descendants.id;
}
