#include "FunctionExpression.h"

namespace jsxer::nodes {
    void FunctionExpression::parse() {
        lineInfo = decoders::d_line_info(reader);
        expression = decoders::d_node(reader);
    }

    string FunctionExpression::to_string() {
        return expression->to_string();
    }
}
