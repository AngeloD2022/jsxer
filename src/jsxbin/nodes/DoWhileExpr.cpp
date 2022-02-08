#include "DoWhileExpr.h"

void DoWhileExpr::parse() {
    body = decoders::d_linfo(scanState);
    condition = decoders::d_node(scanState);
}

string DoWhileExpr::jsx() {
    string label = body.lbl_statement();
    string inner = body.create_body();
    string result;
    result += label + "do {\n";
    result += "  " + inner + '\n';
    result += "} while (" + condition->jsx() + ')';
    return result;
}
