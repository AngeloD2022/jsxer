#pragma once

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class SetDefaultXMLNamespaceExpr : public AbstractNode {
    public:
        explicit SetDefaultXMLNamespaceExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        AbstractNode *defaultNamespaceFxnCall;
    };
}
