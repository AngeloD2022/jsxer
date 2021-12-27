//
// Created by Angelo DeLuca on 12/26/21.
//

#include "WhileStatement.h"

void WhileStatement::parse() {
    bodyInfo = decoders::d_linfo(scanState);
    condition = decoders::d_node(scanState);
}

string WhileStatement::jsx() {
    string result = bodyInfo.lbl_statement() + "while (" +
            (condition == nullptr ? "true" : condition->jsx()) + ") {\n";

    result += bodyInfo.create_body() + "\n}";

    return result;
}
