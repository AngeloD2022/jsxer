#pragma once

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class UnknownNode : public AbstractNode {
    public:
        explicit UnknownNode(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        string id;
        AbstractNode *node;
    };
}
