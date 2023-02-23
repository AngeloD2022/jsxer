#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include "BinaryExpression.h"

namespace jsxer::nodes {
    class AssignmentExpression : public AstNode {
    public:
        explicit AssignmentExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::AssignmentExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        AstOpNode variable;
        AstOpNode expression;
        string literal;
        bool shorthand{};
    };
}
