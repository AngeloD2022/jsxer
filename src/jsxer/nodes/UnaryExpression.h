#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxer;

namespace jsxer { namespace nodes {
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
        AstNode *expression;
    };
} }
