#include "ReturnStatement.h"

void ReturnStatement::parse() {
    lineInfo = decoders::d_line_info(reader);
    expression = decoders::d_node(reader);
}

string ReturnStatement::jsx() {
    string result = expression == nullptr ? "" : ' ' + expression->jsx();
    result = lineInfo.lbl_statement() + "return" + result + ';';
    
    return result;
}
