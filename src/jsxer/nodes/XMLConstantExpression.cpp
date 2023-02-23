#include "XMLConstantExpression.h"

namespace jsxer::nodes {
    void XMLConstantExpression::parse() {
        size_t length = decoders::d_length(reader);

        for (int i = 0; i < length; ++i) {
            AstOpNode child_node = decoders::d_node(reader);
            size_t child_length = decoders::d_length(reader);
            children[child_node] = child_length;
        }
    }

    string XMLConstantExpression::to_string() {
        static const int TYPE_NORMAL = 0;
        static const int TYPE_ELEM_PLACEHOLDER = 1;
        static const int TYPE_ATTR_PLACEHOLDER = 2;
        static const int TYPE_VALUE_PLACEHOLDER = 3;

        string result;

        for (const auto& child: children) {
            if (child.second == TYPE_NORMAL) {
                result += child.first->to_string();
            } else {
                result += " + " + child.first->to_string() + " + ";
            }
        }

        return result;
    }
}
