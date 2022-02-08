#pragma once

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class IndexingIncrementExpr : public AbstractNode {
    public:
        explicit IndexingIncrementExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        AbstractNode *variable;
        int operation;
        bool postfix;
    };
}
