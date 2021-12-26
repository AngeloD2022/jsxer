//
// Created by Angelo DeLuca on 12/26/21.
//

#ifndef JSXBIN_DECOMPILER_SETDEFAULTXMLNAMESPACEEXPR_H
#define JSXBIN_DECOMPILER_SETDEFAULTXMLNAMESPACEEXPR_H

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

#endif //JSXBIN_DECOMPILER_SETDEFAULTXMLNAMESPACEEXPR_H
