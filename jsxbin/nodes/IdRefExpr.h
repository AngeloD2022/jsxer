//
// Created by Angelo DeLuca on 12/21/21.
//

#ifndef JSXBIN_DECOMPILER_IDREFEXPR_H
#define JSXBIN_DECOMPILER_IDREFEXPR_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class IdRefExpr : public AbstractNode {
    public:
        explicit IdRefExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::reference reference;
        int type;
    };
}

#endif //JSXBIN_DECOMPILER_IDREFEXPR_H
