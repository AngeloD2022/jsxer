#pragma once

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class ArrayIndexingExpr : public AbstractNode {
    public:
        explicit ArrayIndexingExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        string arrayName;
        string expression;
    };
}
