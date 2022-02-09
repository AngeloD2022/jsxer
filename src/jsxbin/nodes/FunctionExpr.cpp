#include "FunctionExpr.h"

void FunctionExpr::parse() {
    lineInfo = decoders::d_line_info(reader);
    expression = decoders::d_node(reader);
}

string FunctionExpr::to_string() {
    return expression->to_string();
}
