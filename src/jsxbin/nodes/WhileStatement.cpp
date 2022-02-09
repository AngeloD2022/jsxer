#include "WhileStatement.h"

void WhileStatement::parse() {
    bodyInfo = decoders::d_line_info(reader);
    condition = decoders::d_node(reader);
}

string WhileStatement::jsx() {
    string result = bodyInfo.lbl_statement() + "while (" +
            (condition == nullptr ? "true" : condition->jsx()) + ") {\n";

    result += bodyInfo.create_body() + "\n}";

    return result;
}
