#include "ExprNode.h"

void ExprNode::parse() {
    lineInfo = decoders::d_line_info(reader);
    expression = decoders::d_node(reader);
}

string ExprNode::jsx() {
    return lineInfo.lbl_statement() + expression->jsx() + ';';
}
