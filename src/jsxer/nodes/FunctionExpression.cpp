#include "FunctionExpression.h"

namespace jsxer::nodes {
    void FunctionExpression::parse() {
        print_tree_node(reader, "FunctionExpression");

        lineInfo = decoders::d_line_info(reader);
        expression = decoders::d_node(reader);
    }

    string FunctionExpression::to_string() {
        return expression->to_string();
    }
}
