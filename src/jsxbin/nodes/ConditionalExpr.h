#pragma once

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class ConditionalExpr : public AbstractNode {
    public:
        explicit ConditionalExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        AbstractNode *condition;
        AbstractNode *node_true;
        AbstractNode *node_false;

    };
}
