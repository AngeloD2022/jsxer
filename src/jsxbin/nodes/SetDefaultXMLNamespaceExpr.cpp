#include "SetDefaultXMLNamespaceExpr.h"

void SetDefaultXMLNamespaceExpr::parse() {
    defaultNamespaceFxnCall = decoders::d_node(reader);
}

string SetDefaultXMLNamespaceExpr::to_string() {
    return defaultNamespaceFxnCall->to_string();
}
