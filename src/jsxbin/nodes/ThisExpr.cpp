#include "ThisExpr.h"

void ThisExpr::parse() {
    reference = decoders::d_ref(reader);
}

string ThisExpr::jsx() {
    return reference.id;
}
