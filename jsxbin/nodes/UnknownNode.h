//
// Created by Angelo DeLuca on 12/26/21.
//

#ifndef JSXBIN_DECOMPILER_UNKNOWNNODE_H
#define JSXBIN_DECOMPILER_UNKNOWNNODE_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class UnknownNode : public AbstractNode {
    public:
        explicit UnknownNode(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        string id;
        AbstractNode *node;
    };
}

#endif //JSXBIN_DECOMPILER_UNKNOWNNODE_H
