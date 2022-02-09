#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class ConditionalExpr : public AstNode {
    public:
        explicit ConditionalExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        AstNode *condition;
        AstNode *node_true;
        AstNode *node_false;

    };
}
