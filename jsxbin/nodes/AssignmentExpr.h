//
// Created by Angelo DeLuca on 12/1/21.
//

#ifndef JSXBIN_DECOMPILER_ASSIGNMENTEXPR_H
#define JSXBIN_DECOMPILER_ASSIGNMENTEXPR_H

#include "AbstractNode.h"
#include "BinaryExpr.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class AssignmentExpr : public AbstractNode {
    public:

        explicit AssignmentExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        string var_name;
        AbstractNode *expression;
        string literal;
        bool shorthand;
        bool declaration;
    };
}

#endif //JSXBIN_DECOMPILER_ASSIGNMENTEXPR_H
