//
// Created by Angelo DeLuca on 12/1/21.
//

#ifndef JSXBIN_DECOMPILER_DECODERS_H
#define JSXBIN_DECOMPILER_DECODERS_H

#include <string>
#include "ScanState.h"
#include "nodes/AbstractNode.h"
#include "jsxbin.h"
#include <vector>

using namespace std;
using namespace jsxbin::nodes;


namespace jsxbin::decoders {

    struct reference {
        string id;
        bool flag;
    };

    struct line_info {
        int line_number;
        AbstractNode *child;
        vector<string> labels;

        string lbl_statement() {
            string result;
            std::for_each(labels.begin(), labels.end(), [&result](const string& x){result += x +": \n";});
            return result;
        }

        string create_body() const {
            return child == nullptr ? "" : child->jsx();
        }
    };

    AbstractNode* d_node(ScanState &scanState);
    line_info d_linfo(ScanState &scanState);
    string d_variant(ScanState &scanState);
    string d_string(ScanState &scanState);
    string d_number(ScanState &scanState);
    bool d_bool(ScanState &scanState);
    string d_ident(ScanState &scanState);
    int d_length(ScanState &scanState);
    reference d_ref(ScanState &scanState);
    byte d_byte(ScanState &scanState);
    vector<AbstractNode *> d_children(ScanState &scanState);
}


#endif //JSXBIN_DECOMPILER_DECODERS_H
