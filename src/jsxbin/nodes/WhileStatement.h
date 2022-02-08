#pragma once

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class WhileStatement : public AbstractNode {
    public:
        explicit WhileStatement(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info bodyInfo;
        AbstractNode *condition;
    };
}
