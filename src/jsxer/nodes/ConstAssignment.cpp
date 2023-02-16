#include "ConstAssignment.h"

namespace jsxer::nodes {
    void ConstAssignment::parse() {
        name = decoders::d_sid(reader);
        length = decoders::d_length(reader);
        expression = decoders::d_node(reader);
        literal = decoders::d_variant(reader);
        boolean_1 = reader.getBoolean();
        boolean_2 = reader.getBoolean();
    }

    string ConstAssignment::to_string() {
        return "const " + name + " = "
               + (expression == nullptr ? literal : expression->to_string());
    }
}
