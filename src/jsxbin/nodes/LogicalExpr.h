#pragma once

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class LogicalExpr : public AbstractNode {
    public:
        explicit LogicalExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        string opName;
        AbstractNode *leftExpr;
        AbstractNode *rightExpr;
        string leftLiteral;
        string rightLiteral;
    };
}
