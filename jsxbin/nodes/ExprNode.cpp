//
// Created by Angelo DeLuca on 12/20/21.
//

#include "ExprNode.h"

void ExprNode::parse() {
    lineInfo = decoders::d_linfo(scanState);
    expression = decoders::d_node(scanState);
}

string ExprNode::jsx() {
    return lineInfo.lbl_statement() + expression->jsx();
}
