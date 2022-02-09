#include "DeleteExpr.h"

void DeleteExpr::parse() {
    name = decoders::d_ident(reader);
    argument = decoders::d_node(reader);
}

string DeleteExpr::jsx() {
    return name + ' ' + argument->jsx();
}
