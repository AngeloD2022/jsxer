#include "DeleteExpr.h"

void DeleteExpr::parse() {
    name = decoders::d_ident(scanState);
    argument = decoders::d_node(scanState);
}

string DeleteExpr::jsx() {
    return name + ' ' + argument->jsx();
}
