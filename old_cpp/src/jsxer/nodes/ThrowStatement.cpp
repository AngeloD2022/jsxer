#include "ThrowStatement.h"

namespace jsxer::nodes {
    void ThrowStatement::parse() {
        lineInfo = decoders::d_line_info(reader);
        expression = decoders::d_node(reader);
    }

    string ThrowStatement::to_string() {
        return "throw " + expression->to_string() + ';';
    }
}
