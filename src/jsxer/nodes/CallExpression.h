#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include "ListExpression.h"

namespace jsxer::nodes {
    class CallExpression : public AstNode {
    public:
        explicit CallExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::CallExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        AstOpNode function;
        AstOpNode args;
        bool constructorCall{};
    };
}
