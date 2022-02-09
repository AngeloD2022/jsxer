#include "XMLAccessorExpr.h"

void XMLAccessorExpr::parse() {
    reference = decoders::d_ref(reader);
    object = decoders::d_node(reader);
    member = decoders::d_node(reader);
}

string XMLAccessorExpr::jsx() {
    return object->jsx() + '.' + member->jsx();
}
