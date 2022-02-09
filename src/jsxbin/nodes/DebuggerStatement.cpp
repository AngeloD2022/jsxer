#include "DebuggerStatement.h"

void DebuggerStatement::parse() {
    lineInfo = decoders::d_line_info(reader);
}

string DebuggerStatement::jsx() {
    return lineInfo.lbl_statement() + "debugger";
}
