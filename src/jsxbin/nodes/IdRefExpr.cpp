#include "IdRefExpr.h"

void IdRefExpr::parse() {
    reference = decoders::d_ref(reader);
    type = decoders::d_length(reader);
}

string IdRefExpr::jsx() {
    return reference.id;
}
