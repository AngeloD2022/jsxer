#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class UnaryExpr : public AstNode {
    public:
        explicit UnaryExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        string op;
        AstNode *expression;
    };
} }
