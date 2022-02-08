#pragma once

#include "AbstractNode.h"
#include "../decoders.h"
#include <algorithm>

using namespace jsxbin;

namespace jsxbin::nodes {
    class StatementList : public AbstractNode {
    public:
        explicit StatementList(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        size_t length;
        decoders::line_info body;
        vector<AbstractNode*> statements;
    };
}
