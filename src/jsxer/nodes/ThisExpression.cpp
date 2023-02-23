#include "ThisExpression.h"
#include "../util.h"

namespace jsxer::nodes {
    void ThisExpression::parse() {
        reference = decoders::d_literal_ref(reader);
    }

    string ThisExpression::to_string() {
        // return utils::to_string(reference.id);
        return "this";
    }
}
