#pragma once

#include "AbstractNode.h"
#include "../decoders.h"
#include "ArgumentList.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class FunctionCallExpr : public AbstractNode {
    public:
        explicit FunctionCallExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        AbstractNode *function;
        AbstractNode *args;
        bool constructorCall;
    };
}
