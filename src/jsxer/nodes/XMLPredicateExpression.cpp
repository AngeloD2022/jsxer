#include "XMLPredicateExpression.h"

namespace jsxer::nodes {
    void XMLPredicateExpression::parse() {
        reference = decoders::d_ref(reader);
        object = decoders::d_node(reader);
        member = decoders::d_node(reader);
    }

    string XMLPredicateExpression::to_string() {
        return object->to_string() + '.' + member->to_string();
    }
}
