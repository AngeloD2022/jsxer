#include "ObjectExpr.h"

void ObjectExpr::parse() {
    objectId = decoders::d_sid(reader);

    size_t child_count = decoders::d_length(reader);

    for (int i = 0; i < child_count; ++i) {
        string id = decoders::d_sid(reader);
        AstNode* node = decoders::d_node(reader);
        properties[id] = node;
    }
}

string ObjectExpr::to_string() {
    string result = "{";

    if (!properties.empty()) {
        int i = 0;
        for(std::pair<string, AstNode*> entry : properties){
            if (decoders::valid_id(entry.first)) {
                // TODO: Properly JSON stringify the string literal
                result += '\"' + entry.first + '\"';
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
