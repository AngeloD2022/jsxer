#pragma once

#include "AbstractNode.h"
#include "../decoders.h"
#include <vector>

using namespace jsxbin;

namespace jsxbin::nodes {
    class ArgumentList : public AbstractNode {
    public:
        explicit ArgumentList(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

        vector<AbstractNode*> arguments;

    private:
        bool unkValue;

    };
}
