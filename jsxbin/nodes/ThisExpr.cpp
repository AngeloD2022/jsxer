//
// Created by Angelo DeLuca on 12/26/21.
//

#include "ThisExpr.h"

void ThisExpr::parse() {
    reference = decoders::d_ref(scanState);
}

string ThisExpr::jsx() {
    return reference.id;
}
