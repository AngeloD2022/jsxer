//
// Created by Angelo DeLuca on 12/20/21.
//

#include "ForInStatement.h"

void ForInStatement::parse() {
    bodyInfo = decoders::d_linfo(scanState);
    loopVariable = decoders::d_node(scanState);
    objExpression = decoders::d_node(scanState);
    length = decoders::d_length(scanState);
    id = decoders::d_ident(scanState);

    if (scanState.get_version() == jsxbin_version::VERSION_2)
        forEach = decoders::d_bool(scanState);
}

string ForInStatement::jsx() {
    string result;
    result += bodyInfo.lbl_statement();

    result += forEach ? "for each (var " : "for (var ";
    result += loopVariable->jsx();
    result += " in ";
    result += objExpression->jsx();
    result += ") {{ \n" + bodyInfo.create_body() + '}';

    return result;
}
