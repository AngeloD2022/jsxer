#include "XMLDoubleDotDescendantsExpr.h"

void XMLDoubleDotDescendantsExpr::parse() {
    descendants = decoders::d_ref(reader);
    object = decoders::d_node(reader);

    decoders::d_node(reader);
    decoders::d_node(reader);
}

string XMLDoubleDotDescendantsExpr::to_string() {
    return object->to_string() + ".." + descendants.id;
}
