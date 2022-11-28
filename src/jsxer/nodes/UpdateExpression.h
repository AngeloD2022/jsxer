#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxer;

namespace jsxer { namespace nodes {
    class UpdateExpression : public AstNode {
    public:
        explicit UpdateExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::UpdateExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        shared_ptr<AstNode> variable = nullptr;
        int operation = 0;
        bool postfix = false;
    };
} }
