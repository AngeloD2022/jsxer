#pragma once

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class TryStatement : public AbstractNode {
    public:
        explicit TryStatement(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:

        struct tc_layer {
            string arg;
            AbstractNode *exceptionFilter;
            AbstractNode *catchBlock;
        };

        decoders::line_info tryBlock;
        AbstractNode *finallyBlock;
        vector<tc_layer> layers;
        int length;
    };
}
