#pragma once

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class IfStatement : public AbstractNode {
    public:
        explicit IfStatement(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info bodyInfo;
        AbstractNode *test;
        AbstractNode *otherwise;
    };
}
