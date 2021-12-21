//
// Created by Angelo DeLuca on 12/21/21.
//

#include "IdRefExpr.h"

void IdRefExpr::parse() {
    reference = decoders::d_ref(scanState);
    type = decoders::d_length(scanState);
}

string IdRefExpr::jsx() {
    return reference.id;
}
