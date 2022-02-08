#include "DebuggerStatement.h"

void DebuggerStatement::parse() {
    lineInfo = decoders::d_linfo(scanState);
}

string DebuggerStatement::jsx() {
    return lineInfo.lbl_statement() + "debugger";
}
