#include "BreakStatement.h"

namespace jsxer::nodes {
    void BreakStatement::parse() {
        labelInfo = decoders::d_line_info(reader);
        jmpLocation = decoders::d_sid(reader);
        breakStatement = reader.getBoolean();
    }

    string BreakStatement::to_string() {
        string result = labelInfo.lbl_statement();

        if (breakStatement)
            result += "break ";
        else
            result += "continue ";

        result += jmpLocation + ';';

        return result;
    }
}
