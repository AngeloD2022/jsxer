#include "XMLUnaryRefExpression.h"

namespace jsxer::nodes {
    void XMLUnaryRefExpression::parse() {
        id = decoders::d_sid(reader);
        node = decoders::d_node(reader);
    }

    string XMLUnaryRefExpression::to_string() {
        return "<< DECOMPILER: NO SYNTAX CORRESPONDENCE >>";
    }
}
