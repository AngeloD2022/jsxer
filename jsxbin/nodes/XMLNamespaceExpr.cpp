//
// Created by Angelo DeLuca on 12/26/21.
//

#include "XMLNamespaceExpr.h"

void XMLNamespaceExpr::parse() {
    namespaceObject = decoders::d_ref(scanState);
    object = decoders::d_node(scanState);
    decoders::d_node(scanState);
    decoders::d_node(scanState);
    xmlId = decoders::d_ident(scanState);
}

string XMLNamespaceExpr::jsx() {
    string ns = namespaceObject.flag ? '@' + namespaceObject.id : namespaceObject.id;
    return object->jsx() + '.' + ns + "::" + xmlId;
}
