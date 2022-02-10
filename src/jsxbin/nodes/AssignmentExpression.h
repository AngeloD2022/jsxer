#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include "BinaryExpression.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class AssignmentExpression : public AstNode {
    public:
        explicit AssignmentExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::AssignmentExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        AstNode *variable;
        AstNode *expression;
        string literal;
        bool shorthand;
    };
} }
