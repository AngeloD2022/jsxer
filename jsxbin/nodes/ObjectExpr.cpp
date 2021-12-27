//
// Created by Angelo DeLuca on 12/26/21.
//

#include "ObjectExpr.h"

void ObjectExpr::parse() {
    objectId = decoders::d_ident(scanState);

    size_t child_count = decoders::d_length(scanState);
    for (int i = 0; i < child_count; ++i) {
        string id = decoders::d_ident(scanState);
        AbstractNode *node = decoders::d_node(scanState);
        properties.insert_or_assign(id, node);
    }
}

string ObjectExpr::jsx() {
    string result;

    if (properties.empty()){
        result = "{}";
    } else {

        result += "\n{";

        std::for_each(properties.begin(), properties.end(), [&](const std::pair<string, AbstractNode*>& entry){
            // for js dictionaries

            if (decoders::valid_id(entry.first)) {
                result += '\"' + entry.first + '\"';
            } else {
                result += entry.first;
            }

            // fixme: extra comma added, fix later
            result += " :" + entry.second->jsx() + ",\n";

            return true;
        });

        result += '}';
    }

    return result;
}
