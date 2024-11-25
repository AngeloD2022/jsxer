#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class ConstAssignment : public AstNode {
    public:
        explicit ConstAssignment(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::ConstAssignment;
        }

        void parse() override;

        string to_string() override;

    private:
        string name;
        size_t length{};
        AstOpNode expression;
        string literal;
        bool boolean_1{};
        bool boolean_2{};
    };
}
