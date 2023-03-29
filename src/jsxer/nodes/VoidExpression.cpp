#include "VoidExpression.h"

namespace jsxer::nodes {
    void VoidExpression::parse() {
        AstNode::parse();

        defaultNamespaceFxnCall = decoders::d_node(reader);
    }

    string VoidExpression::to_string() {
        return defaultNamespaceFxnCall->to_string();
    }
}
