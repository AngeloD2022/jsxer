#include "ObjectExpr.h"

void ObjectExpr::parse() {
    objectId = decoders::d_ident(reader);

    size_t child_count = decoders::d_length(reader);
    for (int i = 0; i < child_count; ++i) {
        string id = decoders::d_ident(reader);
        AstNode *node = decoders::d_node(reader);
        properties.insert_or_assign(id, node);
    }
}

string ObjectExpr::jsx() {
    string result;

    if (properties.empty()){
        result = "{}";
    } else {

        result += "{";

        int i = 0;
        for(std::pair<string, AstNode*> entry : properties){
            if (decoders::valid_id(entry.first)) {
                result += '\"' + entry.first + '\"';
            } else {
                result += entry.first;
            }

            result += ": " + entry.second->jsx();

            if (i+1 < properties.size())
                result += ", ";

            i++;
        }

        result += '}';
    }

    return result;
}
