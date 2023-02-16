#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class LogicalExpression : public AstNode {
    public:
        explicit LogicalExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::LogicalExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        string opName;
        AstOpNode leftExpr;
        AstOpNode rightExpr;
        string leftLiteral;
        string rightLiteral;
    };
}
