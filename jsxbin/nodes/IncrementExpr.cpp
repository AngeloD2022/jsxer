//
// Created by Angelo DeLuca on 12/21/21.
//

#include "IncrementExpr.h"

void IncrementExpr::parse() {
    id = decoders::d_ident(scanState);
    length = decoders::d_length(scanState);
    operation = decoders::d_number(scanState);

}

string IncrementExpr::jsx() {
    string op = operation == "1" ? "++" : "--";
    return postfix ? id + op : op + id;
}
