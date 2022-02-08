#pragma once

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class UnaryExpr : public AbstractNode {
    public:
        explicit UnaryExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        string op;
        AbstractNode *expression;
    };
}
