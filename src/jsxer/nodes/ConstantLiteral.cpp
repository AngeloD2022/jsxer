#include "ConstantLiteral.h"

namespace jsxer::nodes {
    void ConstantLiteral::parse() {
        print_tree_node(reader, "ConstantLiteral");

        value = decoders::d_variant(reader);
    }

    string ConstantLiteral::to_string() {
        return value;
    }
}
