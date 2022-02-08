#include "ThisExpr.h"

void ThisExpr::parse() {
    reference = decoders::d_ref(scanState);
}

string ThisExpr::jsx() {
    return reference.id;
}
