#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include "ListExpression.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class CallExpression : public AstNode {
    public:
        explicit CallExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::CallExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        AstNode *function = nullptr;
        AstNode *args = nullptr;
        bool constructorCall;
    };
} }
