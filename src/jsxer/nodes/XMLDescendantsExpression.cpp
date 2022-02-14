#include "XMLDescendantsExpression.h"

void XMLDescendantsExpression::parse() {
    descendants = decoders::d_ref(reader);
    object = decoders::d_node(reader);

    decoders::d_node(reader);
    decoders::d_node(reader);
}

string XMLDescendantsExpression::to_string() {
    return object->to_string() + ".." + descendants.id;
}
