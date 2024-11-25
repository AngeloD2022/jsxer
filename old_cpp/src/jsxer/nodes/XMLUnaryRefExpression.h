#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class XMLUnaryRefExpression : public AstNode {
    public:
        explicit XMLUnaryRefExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::XMLUnaryRefExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        string id;
        AstOpNode node;
    };
}
