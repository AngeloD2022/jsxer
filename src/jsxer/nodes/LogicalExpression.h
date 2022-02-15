#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxer;

namespace jsxer { namespace nodes {
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
        AstNode *leftExpr;
        AstNode *rightExpr;
        string leftLiteral;
        string rightLiteral;
    };
} }
