//
// Created by Angelo DeLuca on 12/16/21.
//

#ifndef JSXBIN_DECOMPILER_DELETEEXPR_H
#define JSXBIN_DECOMPILER_DELETEEXPR_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class DeleteExpr : public AbstractNode {
    public:
        explicit DeleteExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        string name;
        AbstractNode *argument;
    };
}

#endif //JSXBIN_DECOMPILER_DELETEEXPR_H
