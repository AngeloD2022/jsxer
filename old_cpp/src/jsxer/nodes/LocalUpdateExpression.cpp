#include "LocalUpdateExpression.h"


namespace jsxer::nodes {
    void LocalUpdateExpression::parse() {
        id = decoders::d_sid(reader);
        length = decoders::d_length(reader);
        operation = decoders::d_number(reader);
        postfix = reader.getBoolean();
    }

    string LocalUpdateExpression::to_string() {
        string op = operation == "1" ? "++" : "--";
        return postfix ? id + op : op + id;
    }
}
