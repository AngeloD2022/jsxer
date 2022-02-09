#include "IncrementExpr.h"

void IncrementExpr::parse() {
    id = decoders::d_sid(reader);
    length = decoders::d_length(reader);
    operation = decoders::d_number(reader);
    postfix = decoders::d_bool(reader);
}

string IncrementExpr::to_string() {
    string op = operation == "1" ? "++" : "--";
    return postfix ? id + op : op + id;
}
