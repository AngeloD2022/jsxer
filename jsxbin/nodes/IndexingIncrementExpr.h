//
// Created by asola on 12/21/2021.
//

#ifndef JSXBIN_DECOMPILER_INDEXINGINCREMENTEXPR_H
#define JSXBIN_DECOMPILER_INDEXINGINCREMENTEXPR_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class IndexingIncrementExpr : public AbstractNode {
    public:
        explicit IndexingIncrementExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        AbstractNode *variable;
        int operation;
        bool postfix;
    };
}

#endif //JSXBIN_DECOMPILER_INDEXINGINCREMENTEXPR_H
