#include "IndexingIncrementExpr.h"

void IndexingIncrementExpr::parse() {
    variable = decoders::d_node(scanState);
    operation = decoders::d_literal_num(scanState);
    postfix = decoders::d_bool(scanState);
}

string IndexingIncrementExpr::jsx() {
    string op = operation == 1 ? "++" : "--";
    return postfix ?  variable->jsx() + op : op + variable->jsx() ;
}
