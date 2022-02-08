#pragma once

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class ForStatement : public AbstractNode {
    public:
        explicit ForStatement(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info bodyInfo;
        AbstractNode *loopVar;
        string iteratorInitial;
        AbstractNode *upperBound;
        string stepSize;
        int length;
        string comparisonOperator;
    };
}
