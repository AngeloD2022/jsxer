#pragma once

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class IncrementExpr : public AbstractNode {
    public:
        explicit IncrementExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        string id;
        int length;
        string operation;
        bool postfix;
    };
}
