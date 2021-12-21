//
// Created by Angelo DeLuca on 12/21/21.
//

#include "FunctionExpr.h"

void FunctionExpr::parse() {
    lineInfo = decoders::d_linfo(scanState);
    expression = decoders::d_node(scanState);
}

string FunctionExpr::jsx() {
    return expression->jsx();
}
