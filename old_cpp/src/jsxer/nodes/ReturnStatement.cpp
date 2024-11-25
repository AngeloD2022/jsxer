#include "ReturnStatement.h"

namespace jsxer::nodes {
    void ReturnStatement::parse() {
        lineInfo = decoders::d_line_info(reader);
        expression = decoders::d_node(reader);
    }

    string ReturnStatement::to_string() {
        string result = expression == nullptr ? "" : ' ' + expression->to_string();
        result = lineInfo.lbl_statement() + "return" + result + ';';

        return result;
    }
}