//
// Created by Angelo DeLuca on 12/26/21.
//

#ifndef JSXBIN_DECOMPILER_XMLACCESSOREXPR_H
#define JSXBIN_DECOMPILER_XMLACCESSOREXPR_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class XMLAccessorExpr : public AbstractNode {
    public:
        explicit XMLAccessorExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::reference reference;
        AbstractNode *object;
        AbstractNode *member;
    };
}

#endif //JSXBIN_DECOMPILER_XMLACCESSOREXPR_H
