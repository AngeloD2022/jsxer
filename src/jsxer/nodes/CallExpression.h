#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include "ListExpression.h"

using namespace jsxer;

namespace jsxer { namespace nodes {
    class CallExpression : public AstNode {
    public:
        explicit CallExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::CallExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        shared_ptr<AstNode> function = nullptr;
        shared_ptr<AstNode> args = nullptr;
        bool constructorCall;
    };
} }
