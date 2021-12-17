//
// Created by Angelo DeLuca on 12/16/21.
//

#ifndef JSXBIN_DECOMPILER_DOWHILEEXPR_H
#define JSXBIN_DECOMPILER_DOWHILEEXPR_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class DoWhileExpr : public AbstractNode {
    public:
        explicit DoWhileExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info body;
        AbstractNode *condition;
    };
}

#endif //JSXBIN_DECOMPILER_DOWHILEEXPR_H
