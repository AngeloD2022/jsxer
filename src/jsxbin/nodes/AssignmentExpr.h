#pragma once

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
