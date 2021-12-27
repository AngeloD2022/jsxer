//
// Created by Angelo DeLuca on 12/26/21.
//

#include "XMLAssignmentExpr.h"

void XMLAssignmentExpr::parse() {
    size_t length = decoders::d_length(scanState);

    for (int i = 0; i < length; ++i){
        children.insert_or_assign(decoders::d_node(scanState), decoders::d_length(scanState));
    }

}

string XMLAssignmentExpr::jsx() {

    static const int TYPE_NORMAL = 0;
    static const int TYPE_ELEM_PLACEHOLDER = 1;
    static const int TYPE_ATTR_PLACEHOLDER = 2;
    static const int TYPE_VALUE_PLACEHOLDER = 3;

    string result;

    for (std::pair<AbstractNode*, int> child : children){
        if (child.second == TYPE_NORMAL){
            result += child.first->jsx();
        } else {
            result += " + " + child.first->jsx() + " + ";
        }
    }

    return result;
}
