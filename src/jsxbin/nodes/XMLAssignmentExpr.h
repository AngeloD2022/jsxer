#pragma once

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class XMLAssignmentExpr : public AbstractNode {
    public:
        explicit XMLAssignmentExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        map<AbstractNode*, int> children;


    };
}
