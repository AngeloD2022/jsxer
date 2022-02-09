#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class UnaryExpr : public AstNode {
    public:
        explicit UnaryExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        string op;
        AstNode *expression;
    };
}
