#include "XMLQualifiedNameExpression.h"

void XMLQualifiedNameExpression::parse() {
    descendants = decoders::d_ref(reader);
    object = decoders::d_node(reader);

    decoders::d_node(reader);
    decoders::d_node(reader);
}

string XMLQualifiedNameExpression::to_string() {
    return object->to_string() + ".." + descendants.id;
}
