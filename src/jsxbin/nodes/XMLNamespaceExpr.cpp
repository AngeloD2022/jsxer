#include "XMLNamespaceExpr.h"

void XMLNamespaceExpr::parse() {
    namespaceObject = decoders::d_ref(reader);
    object = decoders::d_node(reader);
    decoders::d_node(reader);
    decoders::d_node(reader);
    xmlId = decoders::d_ident(reader);
}

string XMLNamespaceExpr::jsx() {
    string ns = namespaceObject.flag ? '@' + namespaceObject.id : namespaceObject.id;
    return object->jsx() + '.' + ns + "::" + xmlId;
}
