#include "ThisExpression.h"

void ThisExpression::parse() {
    reference = decoders::d_ref(reader);
}

string ThisExpression::to_string() {
    return reference.id;
}
