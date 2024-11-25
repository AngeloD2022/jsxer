#include "WhileStatement.h"

namespace jsxer::nodes {
    void WhileStatement::parse() {
        bodyInfo = decoders::d_line_info(reader);
        condition = decoders::d_node(reader);
    }

    string WhileStatement::to_string() {
        string result = bodyInfo.lbl_statement() + "while (" +
                        (condition == nullptr ? "true" : condition->to_string()) + ") {\n";

        result += bodyInfo.create_body() + "\n}";

        return result;
    }
}
