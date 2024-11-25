#include "ExpressionStatement.h"

namespace jsxer::nodes {
    void ExpressionStatement::parse() {
        lineInfo = decoders::d_line_info(reader);
        expression = decoders::d_node(reader);
    }

    string ExpressionStatement::to_string() {
        return lineInfo.lbl_statement() + expression->to_string() + ';';
    }
}