#include "ForStatement.h"

void ForStatement::parse() {
    bodyInfo = decoders::d_line_info(reader);
    initial = decoders::d_node(reader);
    test = decoders::d_node(reader);
    update = decoders::d_node(reader);
}

string ForStatement::to_string() {
    string result;
    result += bodyInfo.lbl_statement();
    result += "for (" + (initial == nullptr ? "" : initial->to_string());
    result += "; " + (test == nullptr ? "" : test->to_string());
    result += "; " + (update == nullptr ? "" : update->to_string());
    result += ") { \n" + bodyInfo.create_body() + '}';
    return result;
}
