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

        result += varname;

        // attempt to simplify the update expression...
        string op = "+";
        bool is_negative = stepSize[0] == '-';
        string value_assigned = is_negative ? stepSize.substr(1) : stepSize;

        // we want to alter the operator to be functionally equivalent, such that the step value can be unsigned...
        if (is_negative)
            op = "-";
        if (value_assigned == "1")
            result += op + op;
        else
            result += " " + op + "= " + value_assigned;

        result += ") {\n" + bodyInfo.create_body() + "\n}";

        return result;
    }
}
