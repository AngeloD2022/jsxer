//
// Created by Angelo DeLuca on 12/16/21.
//

#include "DebuggerStatement.h"

void DebuggerStatement::parse() {
    lineInfo = decoders::d_linfo(scanState);
}

string DebuggerStatement::jsx() {
    return lineInfo.lbl_statement() + "debugger";
}
