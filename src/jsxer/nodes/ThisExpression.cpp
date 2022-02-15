#include "ThisExpression.h"
#include "../util.h"

void ThisExpression::parse() {
    reference = decoders::d_ref(reader);
}

string ThisExpression::to_string() {
    return utils::to_string(reference.id);
}
