#include "ForInStatement.h"

namespace jsxer::nodes {
    void ForInStatement::parse() {
        bodyInfo = decoders::d_line_info(reader);
        loopVariable = decoders::d_node(reader);
        objExpression = decoders::d_node(reader);
        length = decoders::d_length(reader);
        id = decoders::d_sid(reader);

        if (reader.version() >= JsxbinVersion::v20)
            // strange, because a "for-each" statement is not described in the ECMAScript3 standard.
            forEach = reader.getBoolean();
    }

    string ForInStatement::to_string() {
        string result;
        result += bodyInfo.lbl_statement();

        result += forEach ? "for each (var " : "for (var ";
        result += loopVariable->to_string();
        result += " in ";
        result += objExpression->to_string();
        result += ") { \n" + bodyInfo.create_body() + "\n}";

        return result;
    }
}
