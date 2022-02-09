#include "ForInStatement.h"

void ForInStatement::parse() {
    bodyInfo = decoders::d_line_info(reader);
    loopVariable = decoders::d_node(reader);
    objExpression = decoders::d_node(reader);
    length = decoders::d_length(reader);
    id = decoders::d_ident(reader);

    if (reader.get_version() >= JsxbinVersion::v20)
        forEach = decoders::d_bool(reader);
}

string ForInStatement::jsx() {
    string result;
    result += bodyInfo.lbl_statement();

    result += forEach ? "for each (var " : "for (var ";
    result += loopVariable->jsx();
    result += " in ";
    result += objExpression->jsx();
    result += ") { \n" + bodyInfo.create_body() + '}';

    return result;
}
