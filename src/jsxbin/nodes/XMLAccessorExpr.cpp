#include "XMLAccessorExpr.h"

void XMLAccessorExpr::parse() {
    reference = decoders::d_ref(scanState);
    object = decoders::d_node(scanState);
    member = decoders::d_node(scanState);
}

string XMLAccessorExpr::jsx() {
    return object->jsx() + '.' + member->jsx();
}
