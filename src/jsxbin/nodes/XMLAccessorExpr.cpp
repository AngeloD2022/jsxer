#include "XMLAccessorExpr.h"

void XMLAccessorExpr::parse() {
    reference = decoders::d_ref(reader);
    object = decoders::d_node(reader);
    member = decoders::d_node(reader);
}

string XMLAccessorExpr::to_string() {
    return object->to_string() + '.' + member->to_string();
}
