#pragma once

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class XMLNamespaceExpr : public AbstractNode {
    public:
        explicit XMLNamespaceExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::reference namespaceObject;
        AbstractNode *object;
        string xmlId;
    };
}
