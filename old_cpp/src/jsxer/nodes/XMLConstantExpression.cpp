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

        std::vector<AstOpNode> normals;
        std::vector<AstOpNode> placeholders;

        for (const auto &child: children){
            if (child.second == TYPE_NORMAL){
                normals.push_back(child.first);
                continue;
            }
            placeholders.push_back(child.first);
        }

        if (normals.size() != placeholders.size() + 1 && children.size() > 1)
            return "// Jsxer: XMLConstantExpression syntax recovery failed.";

        for (int i = 0; i < children.size(); ++i) {
            if (!(i & 1)) {
                AstOpNode normal = normals[i / 2];

                result += utils::from_string_literal(normal->to_string());
                continue;
            }
            string placeholder = placeholders[i / 2]->to_string();
            placeholder.erase(placeholder.size()-1, 1);
            result += '{' + placeholder + '}';
        }

        return result;
    }
}
