//
// Created by Angelo DeLuca on 12/20/21.
//

#ifndef JSXBIN_DECOMPILER_EXPRNODE_H
#define JSXBIN_DECOMPILER_EXPRNODE_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class ExprNode : public AbstractNode {
    public:
        explicit ExprNode(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info lineInfo;
        AbstractNode *expression;
    };
}

#endif //JSXBIN_DECOMPILER_EXPRNODE_H
