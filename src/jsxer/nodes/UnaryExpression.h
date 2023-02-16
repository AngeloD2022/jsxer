#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class UnaryExpression : public AstNode {
    public:
        explicit UnaryExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::UnaryExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        string op;
        AstOpNode expression;
    };
}
