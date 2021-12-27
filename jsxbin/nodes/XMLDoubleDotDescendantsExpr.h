//
// Created by Angelo DeLuca on 12/26/21.
//

#ifndef JSXBIN_DECOMPILER_XMLDOUBLEDOTDESCENDANTSEXPR_H
#define JSXBIN_DECOMPILER_XMLDOUBLEDOTDESCENDANTSEXPR_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class XMLDoubleDotDescendantsExpr : public AbstractNode {
    public:
        explicit XMLDoubleDotDescendantsExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::reference descendants;
        AbstractNode *object;
    };
}

#endif //JSXBIN_DECOMPILER_XMLDOUBLEDOTDESCENDANTSEXPR_H
