//
// Created by Angelo DeLuca on 12/26/21.
//

#include "ReturnStatement.h"

void ReturnStatement::parse() {
    lineInfo = decoders::d_linfo(scanState);
    expression = decoders::d_node(scanState);
}

string ReturnStatement::jsx() {
    string result = expression == nullptr ? "" : ' ' + expression->jsx();
    result = lineInfo.lbl_statement() + "return" + result + ';';
    
    return result;
}
