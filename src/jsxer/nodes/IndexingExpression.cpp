#include "IndexingExpression.h"

namespace jsxer::nodes {
    void IndexingExpression::parse() {
        print_tree_node(reader, "IndexingExpression");

        auto ref = decoders::d_literal_ref(reader); // <str, bool>
        auto name = decoders::d_node(reader);
        auto expr = decoders::d_node(reader);

        arrayName = name->to_string();
        expression = expr->to_string();
    }

    string IndexingExpression::to_string() {
        return arrayName + '[' + expression + ']';
    }
}
