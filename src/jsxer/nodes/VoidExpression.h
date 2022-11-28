#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxer;

namespace jsxer { namespace nodes {
    class VoidExpression : public AstNode {
    public:
        explicit VoidExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::VoidExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        shared_ptr<AstNode> defaultNamespaceFxnCall;
    };
} }
