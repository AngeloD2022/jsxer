#include "SimpleForStatement.h"

namespace jsxer::nodes {
    void SimpleForStatement::parse() {
        bodyInfo = decoders::d_line_info(reader);
        loopVar = decoders::d_node(reader);
        iteratorInitial = decoders::d_number(reader);
        upperBound = decoders::d_node(reader);
        stepSize = decoders::d_number(reader);
        length = decoders::d_length(reader);
        comparisonOperator = decoders::d_sid(reader);
    }

    string SimpleForStatement::to_string() {
        string result;
        string varname = loopVar->to_string();
        result += bodyInfo.lbl_statement();
        result += "for (var ";
        result += varname + " = " + iteratorInitial + "; ";
        result += varname + ' ' + comparisonOperator + ' ' + upperBound->to_string() + "; ";

        result += varname + " += " + stepSize;
        result += ") { \n" + bodyInfo.create_body() + '}';

        return result;
    }
}
