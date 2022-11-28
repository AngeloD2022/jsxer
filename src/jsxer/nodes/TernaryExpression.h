#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxer;

namespace jsxer { namespace nodes {
    class TernaryExpression : public AstNode {
    public:
        explicit TernaryExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::TernaryExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        shared_ptr<AstNode> condition;
        shared_ptr<AstNode> node_true;
        shared_ptr<AstNode> node_false;

    };
} }
