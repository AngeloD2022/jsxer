#include "XMLDescendantsExpression.h"

namespace jsxer::nodes {
    void XMLDescendantsExpression::parse() {
        AstNode::parse();

        descendants = decoders::d_literal_ref(reader);
        object = decoders::d_node(reader);

        decoders::d_node(reader);
        decoders::d_node(reader);
    }

    string XMLDescendantsExpression::to_string() {
        return object->to_string() + ".." + utils::to_string(descendants.id);
    }
}
