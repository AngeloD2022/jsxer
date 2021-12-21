//
// Created by Angelo DeLuca on 12/21/21.
//

#ifndef JSXBIN_DECOMPILER_FUNCTIONEXPR_H
#define JSXBIN_DECOMPILER_FUNCTIONEXPR_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class FunctionExpr : public AbstractNode {
    public:
        explicit FunctionExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info lineInfo;
        AbstractNode *expression;
    };
}

#endif //JSXBIN_DECOMPILER_FUNCTIONEXPR_H
