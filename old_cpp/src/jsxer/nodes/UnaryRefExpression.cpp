#include "UnaryRefExpression.h"

namespace jsxer::nodes {
    void UnaryRefExpression::parse() {
        name = decoders::d_operator(reader);
        argument = decoders::d_node(reader);
    }

    string UnaryRefExpression::to_string() {
        return name + ' ' + argument->to_string();
    }
}
