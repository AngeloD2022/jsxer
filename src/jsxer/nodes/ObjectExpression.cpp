#include "ObjectExpression.h"
#include "../util.h"


namespace jsxer::nodes {
    void ObjectExpression::parse() {
        objectId = decoders::d_sid(reader);

        size_t child_count = decoders::d_length(reader);

        for (int i = 0; i < child_count; ++i) {
            string id = decoders::d_sid(reader);
            AstOpNode node = decoders::d_node(reader);
            properties[id] = node;
        }
    }

    string ObjectExpression::to_string() {
        string result = "{";

        if (!properties.empty()) {
            int i = 0;
            for (std::pair<string, AstOpNode> entry: properties) {
                if (!decoders::valid_id(entry.first)) {
                    result += utils::to_string_literal(entry.first);
                } else {
                    result += entry.first;
                }

                result += ": " + entry.second->to_string();

                if ((i + 1) < properties.size())
                    result += ", ";

                i++;
            }
        }

        return result + '}';
    }
}
