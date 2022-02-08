#pragma once

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class ForInStatement : public AbstractNode {
    public:
        explicit ForInStatement(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info bodyInfo;
        AbstractNode *loopVariable;
        AbstractNode *objExpression;
        int length;
        string id;
        bool forEach = false;
    };
}
