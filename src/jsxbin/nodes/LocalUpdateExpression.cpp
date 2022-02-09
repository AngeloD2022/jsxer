#include "LocalUpdateExpression.h"

void LocalUpdateExpression::parse() {
    id = decoders::d_sid(reader);
    length = decoders::d_length(reader);
    operation = decoders::d_number(reader);

    // I CAN'T BELIEVE I FORGOT THIS...
    postfix = decoders::d_bool(reader);
}

string LocalUpdateExpression::to_string() {
    string op = operation == "1" ? "++" : "--";
    return postfix ? id + op : op + id;
}
