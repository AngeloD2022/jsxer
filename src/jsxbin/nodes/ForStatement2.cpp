#include "ForStatement2.h"

void ForStatement2::parse() {
    bodyInfo = decoders::d_linfo(scanState);
    initial = decoders::d_node(scanState);
    test = decoders::d_node(scanState);
    update = decoders::d_node(scanState);
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
