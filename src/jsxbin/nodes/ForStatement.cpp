#include "ForStatement.h"

void ForStatement::parse() {
    bodyInfo = decoders::d_line_info(reader);
    loopVar = decoders::d_node(reader);
    iteratorInitial = decoders::d_number(reader);
    upperBound = decoders::d_node(reader);
    stepSize = decoders::d_number(reader);
    length = decoders::d_length(reader);
    comparisonOperator = decoders::d_ident(reader);
}

string ForStatement::jsx() {
    string result;
    string varname = loopVar->jsx();
    result += bodyInfo.lbl_statement();
    result += "for (var ";
    result += varname + " = " + iteratorInitial + "; ";
    result += varname + ' ' + comparisonOperator + ' ' + upperBound->jsx() + "; ";
    result += varname + " += " + stepSize;
    result += ") { \n" + bodyInfo.create_body() + '}';
    return result;
}
