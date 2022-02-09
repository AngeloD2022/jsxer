#include "IncrementExpr.h"

void IncrementExpr::parse() {
    id = decoders::d_ident(reader);
    length = decoders::d_length(reader);
    operation = decoders::d_number(reader);

    // I CAN'T BELIEVE I FORGOT THIS...
    postfix = decoders::d_bool(reader);
}

string IncrementExpr::jsx() {
    string op = operation == "1" ? "++" : "--";
    return postfix ? id + op : op + id;
}
