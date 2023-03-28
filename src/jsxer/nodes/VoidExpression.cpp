#include "VoidExpression.h"

namespace jsxer::nodes {
    void VoidExpression::parse() {
        print_tree_node(reader, "VoidExpression");

        defaultNamespaceFxnCall = decoders::d_node(reader);
    }

    string VoidExpression::to_string() {
        return defaultNamespaceFxnCall->to_string();
    }
}
