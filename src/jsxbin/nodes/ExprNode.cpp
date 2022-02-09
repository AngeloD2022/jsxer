#include "ExprNode.h"

void ExprNode::parse() {
    lineInfo = decoders::d_line_info(reader);
    expression = decoders::d_node(reader);
}

string ExprNode::to_string() {
    return lineInfo.lbl_statement() + expression->to_string() + ';';
}
