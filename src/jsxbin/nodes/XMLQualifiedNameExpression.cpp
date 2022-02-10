#include "XMLQualifiedNameExpression.h"

void XMLQualifiedNameExpression::parse() {
    namespaceObject = decoders::d_ref(reader);
    object = decoders::d_node(reader);
    decoders::d_node(reader);
    decoders::d_node(reader);
    xmlId = decoders::d_sid(reader);
}

string XMLQualifiedNameExpression::to_string() {
    string ns = namespaceObject.flag ? '@' + namespaceObject.id : namespaceObject.id;
    return object->to_string() + '.' + ns + "::" + xmlId;
}
