//
// Created by Angelo DeLuca on 12/26/21.
//

#include "SetDefaultXMLNamespaceExpr.h"

void SetDefaultXMLNamespaceExpr::parse() {
    defaultNamespaceFxnCall = decoders::d_node(scanState);
}

string SetDefaultXMLNamespaceExpr::jsx() {
    return defaultNamespaceFxnCall->jsx();
}
