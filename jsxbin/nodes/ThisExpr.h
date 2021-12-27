//
// Created by Angelo DeLuca on 12/26/21.
//

#ifndef JSXBIN_DECOMPILER_THISEXPR_H
#define JSXBIN_DECOMPILER_THISEXPR_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class ThisExpr : public AbstractNode {
    public:
        explicit ThisExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::reference reference;
    };
}

#endif //JSXBIN_DECOMPILER_THISEXPR_H
