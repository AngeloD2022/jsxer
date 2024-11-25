#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class ConstantLiteral : public AstNode {
    public:
        explicit ConstantLiteral(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::ConstantLiteral;
        }

        void parse() override;

        string to_string() override;

    private:
        string value;
    };
}
