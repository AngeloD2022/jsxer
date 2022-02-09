#include "ThisExpr.h"

void ThisExpr::parse() {
    reference = decoders::d_ref(reader);
}

string ThisExpr::to_string() {
    return reference.id;
}
