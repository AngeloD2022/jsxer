#pragma once

#include "AbstractNode.h"
#include "../decoders.h"

#include <cstdlib>

using namespace jsxbin;

namespace jsxbin::nodes {
    class MemberExpr : public AbstractNode {
    public:
        explicit MemberExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::reference memberInfo;
        AbstractNode *objInfo;
    };
}
