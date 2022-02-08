#pragma once

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class ThisExpr : public AbstractNode {
    public:
        explicit ThisExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::reference reference;
    };
}
