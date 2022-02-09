#include "FunctionExpr.h"

void FunctionExpr::parse() {
    lineInfo = decoders::d_line_info(reader);
    expression = decoders::d_node(reader);
}

string FunctionExpr::jsx() {
    return expression->jsx();
}
