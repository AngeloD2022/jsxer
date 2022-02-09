#include "ForStatement2.h"

void ForStatement2::parse() {
    bodyInfo = decoders::d_line_info(reader);
    initial = decoders::d_node(reader);
    test = decoders::d_node(reader);
    update = decoders::d_node(reader);
}

string ForStatement2::jsx() {
    string result;
    result += bodyInfo.lbl_statement();
    result += "for (" + (initial == nullptr ? "" : initial->jsx());
    result += "; " + (test == nullptr ? "" : test->jsx());
    result += "; " + (update == nullptr ? "" : update->jsx());
    result += ") { \n" + bodyInfo.create_body() + '}';
    return result;
}
