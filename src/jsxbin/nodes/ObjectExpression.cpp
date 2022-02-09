#include "ObjectExpression.h"

void ObjectExpression::parse() {
    objectId = decoders::d_sid(reader);

    size_t child_count = decoders::d_length(reader);

    for (int i = 0; i < child_count; ++i) {
        properties[decoders::d_sid(reader)] = decoders::d_node(reader);
    }
}

string ObjectExpression::to_string() {
    string result = "{";

    if (!properties.empty()) {
        int i = 0;
        for(std::pair<string, AstNode*> entry : properties){
            if (decoders::valid_id(entry.first)) {
                // TODO: Properly JSON stringify the string property key
                result += '\"' + entry.first + '\"';
            } else {
                result += entry.first;
            }

            result += ": " + entry.second->to_string();

            if (i+1 < properties.size())
                result += ", ";

            i++;
        }
    }

    result += "}";

    return result;
}
