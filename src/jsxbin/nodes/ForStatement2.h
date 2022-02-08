#pragma once

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class ForStatement2 : public AbstractNode {
    public:
        explicit ForStatement2(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info bodyInfo;
        AbstractNode *initial;
        AbstractNode *test;
        AbstractNode *update;
    };
}
