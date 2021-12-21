//
// Created by asola on 12/21/2021.
//

#ifndef JSXBIN_DECOMPILER_LOGICALEXPR_H
#define JSXBIN_DECOMPILER_LOGICALEXPR_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class LogicalExpr : public AbstractNode {
    public:
        explicit LogicalExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        string opName;
        AbstractNode *leftExpr;
        AbstractNode *rightExpr;
        string leftLiteral;
        string rightLiteral;
    };
}

#endif //JSXBIN_DECOMPILER_LOGICALEXPR_H
