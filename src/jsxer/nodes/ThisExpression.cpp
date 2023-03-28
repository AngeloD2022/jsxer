#include "ThisExpression.h"

namespace jsxer::nodes {
    void ThisExpression::parse() {
        print_tree_node(reader, "ThisExpression");

        reference = decoders::d_literal_ref(reader);
    }

    string ThisExpression::to_string() {
        // return utils::to_string(reference.id);
        return "this";
    }
}
