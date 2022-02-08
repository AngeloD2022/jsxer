#pragma once

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class DeleteExpr : public AbstractNode {
    public:
        explicit DeleteExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        string name;
        AbstractNode *argument;
    };
}
