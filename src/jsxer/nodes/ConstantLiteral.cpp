#include "ConstantLiteral.h"

namespace jsxer::nodes {
    void ConstantLiteral::parse() {
        AstNode::parse();

        value = decoders::d_variant(reader);
    }

    string ConstantLiteral::to_string() {
        return value;
    }
}
