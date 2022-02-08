#pragma once

#include "AbstractNode.h"
#include "../decoders.h"
#include "ArgumentList.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class SwitchStatement : public AbstractNode {
    public:
        explicit SwitchStatement(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info lineInfo;
        AbstractNode *switchValue;
        vector<AbstractNode*> cases;
        vector<AbstractNode*> implementations;
    };
}
