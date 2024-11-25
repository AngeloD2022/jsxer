#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class XMLConstantExpression : public AstNode {
    public:
        explicit XMLConstantExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::XMLConstantExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        map<AstOpNode, unsigned long> children;
    };
}
