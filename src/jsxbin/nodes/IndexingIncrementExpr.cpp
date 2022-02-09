#include "IndexingIncrementExpr.h"

void IndexingIncrementExpr::parse() {
    variable = decoders::d_node(reader);
    operation = decoders::d_literal_num(reader);
    postfix = decoders::d_bool(reader);
}

string IndexingIncrementExpr::jsx() {
    string op = operation == 1 ? "++" : "--";
    return postfix ?  variable->jsx() + op : op + variable->jsx() ;
}
