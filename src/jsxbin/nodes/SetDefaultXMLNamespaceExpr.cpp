#include "SetDefaultXMLNamespaceExpr.h"

void SetDefaultXMLNamespaceExpr::parse() {
    defaultNamespaceFxnCall = decoders::d_node(reader);
}

string SetDefaultXMLNamespaceExpr::jsx() {
    return defaultNamespaceFxnCall->jsx();
}
