#pragma once

#include "AbstractNode.h"
#include "../decoders.h"
#include <algorithm>

using namespace jsxbin;

namespace jsxbin::nodes {

    class ObjectExpr : public AbstractNode {
    public:
        explicit ObjectExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        string objectId;
        map<string, AbstractNode*> properties;
    };
}
