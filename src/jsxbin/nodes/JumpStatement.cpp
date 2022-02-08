#include "JumpStatement.h"

void JumpStatement::parse() {
    labelInfo = decoders::d_linfo(scanState);
    jmpLocation = decoders::d_ident(scanState);
    breakStatement = decoders::d_bool(scanState);
}

string JumpStatement::jsx() {
    string result = labelInfo.lbl_statement();

    if (breakStatement)
        result += "break ";
    else
        result += "continue ";

    result += jmpLocation + ';';

    return result;
}
