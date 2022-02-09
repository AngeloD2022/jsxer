#include "DeleteExpr.h"

void DeleteExpr::parse() {
    name = decoders::d_sid(reader);
    argument = decoders::d_node(reader);
}

string DeleteExpr::to_string() {
    return name + ' ' + argument->to_string();
}
