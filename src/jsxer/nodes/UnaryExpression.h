#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class UnaryExpression : public AstNode {
    public:
        DEFINE_NODE_TYPE(UnaryExpression);

        explicit UnaryExpression(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        string op;
        AstOpNode expression;
    };
}
