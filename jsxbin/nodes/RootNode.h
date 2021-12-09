//
// Created by Angelo DeLuca on 12/1/21.
//

#ifndef JSXBIN_DECOMPILER_ROOTNODE_H
#define JSXBIN_DECOMPILER_ROOTNODE_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class RootNode : AbstractNode {
    public:
        explicit RootNode(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override {
            child = decoders::d_node(scanState);
        }

        string jsx() override {
            parse();
            return child->jsx();
        }

    private:
        AbstractNode *child = nullptr;
    };
}


#endif //JSXBIN_DECOMPILER_ROOTNODE_H
