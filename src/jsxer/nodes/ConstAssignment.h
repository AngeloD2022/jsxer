#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxer;

namespace jsxer { namespace nodes {
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
        int length;
        shared_ptr<AstNode> expression;
        string literal;
        bool boolean_1;
        bool boolean_2;
    };
} }
