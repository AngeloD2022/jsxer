#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class ConstAssignment : public AstNode {
    public:
        DEFINE_NODE_TYPE(ConstAssignment);

        explicit ConstAssignment(Reader& reader) : AstNode(reader) {}

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
