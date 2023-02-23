#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class UnaryRefExpression : public AstNode {
    public:
        explicit UnaryRefExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::UnaryRefExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        string name;
        AstOpNode argument;
    };
}
