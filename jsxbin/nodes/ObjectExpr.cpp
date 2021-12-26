//
// Created by Angelo DeLuca on 12/26/21.
//

#include "ObjectExpr.h"

void ObjectExpr::parse() {
    objectId = decoders::d_ident(scanState);

    size_t child_count = decoders::d_length(scanState);
    for (int i = 0; i < child_count; ++i) {
        properties.insert_or_assign(decoders::d_ident(scanState), decoders::d_node(scanState));
    }
}

string ObjectExpr::jsx() {
    string result;

    if (properties.empty()){
        result = "{}";
    } else {

        result += "\n{";

        std::for_each(properties.begin(), properties.end(), [&](const std::pair<string, AbstractNode*>& entry){
            // for dictionaries
            if (decoders::valid_id(entry.first)) {
                result += '\"' + entry.first + '\"';
            } else {
                result += entry.first;
            }
            result += " :" + entry.second->jsx() + '\n';

            return true;
        });

        result += '}';
    }

    return result;
}
