//
// Created by Angelo DeLuca on 12/26/21.
//

#ifndef JSXBIN_DECOMPILER_UNARYEXPR_H
#define JSXBIN_DECOMPILER_UNARYEXPR_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class UnaryExpr : public AbstractNode {
    public:
        explicit UnaryExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        string op;
        AbstractNode *expression;
    };
}

#endif //JSXBIN_DECOMPILER_UNARYEXPR_H
