//
// Created by Angelo DeLuca on 12/26/21.
//

#ifndef JSXBIN_DECOMPILER_VALUENODE_H
#define JSXBIN_DECOMPILER_VALUENODE_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class ValueNode : public AbstractNode {
    public:
        explicit ValueNode(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        string value;
    };
}

#endif //JSXBIN_DECOMPILER_VALUENODE_H
