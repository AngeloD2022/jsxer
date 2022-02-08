#pragma once

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class XMLDoubleDotDescendantsExpr : public AbstractNode {
    public:
        explicit XMLDoubleDotDescendantsExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::reference descendants;
        AbstractNode *object;
    };
}
