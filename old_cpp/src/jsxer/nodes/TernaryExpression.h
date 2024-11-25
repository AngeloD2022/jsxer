#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class TernaryExpression : public AstNode {
    public:
        explicit TernaryExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::TernaryExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        AstOpNode condition;
        AstOpNode node_true;
        AstOpNode node_false;
    };
}
