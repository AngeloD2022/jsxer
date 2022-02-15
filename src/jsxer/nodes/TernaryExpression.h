#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class TernaryExpression : public AstNode {
    public:
        explicit TernaryExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::TernaryExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        AstNode* condition;
        AstNode* node_true;
        AstNode* node_false;

    };
} }
