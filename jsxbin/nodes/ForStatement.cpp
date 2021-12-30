//
// Created by Angelo DeLuca on 12/20/21.
//

#include "ForStatement.h"

void ForStatement::parse() {
    bodyInfo = decoders::d_linfo(scanState);
    loopVar = decoders::d_node(scanState);
    iteratorInitial = decoders::d_number(scanState);
    upperBound = decoders::d_node(scanState);
    stepSize = decoders::d_number(scanState);
    length = decoders::d_length(scanState);
    comparisonOperator = decoders::d_ident(scanState);
}

string ForStatement::jsx() {
    string result;
    string varname = loopVar->jsx();
    result += bodyInfo.lbl_statement();
    result += "for (var ";
    result += varname + " = " + iteratorInitial + "; ";
    result += varname + ' ' + comparisonOperator + ' ' + upperBound->jsx() = "; ";
    result += varname + " += " + stepSize;
    result += ") { \n" + bodyInfo.create_body() + '}';
    return result;
}


// Second ForStatement type implementation...
void ForStatement2::parse() {
    bodyInfo = decoders::d_linfo(scanState);
    initial = decoders::d_node(scanState);
    test = decoders::d_node(scanState);
    update = decoders::d_node(scanState);
}

string ForStatement2::jsx() {
    string result;
    result += bodyInfo.lbl_statement();
    result += "for (" + (initial == nullptr ? "" : initial->jsx());
    result += "; " + (test == nullptr ? "" : test->jsx());
    result += "; " + (update == nullptr ? "" : update->jsx());
    result += ") { \n" + bodyInfo.create_body() + '}';
    return result;
}
