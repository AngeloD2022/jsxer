#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class RegExpLiteral : public AstNode {
    public:
        explicit RegExpLiteral(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::RegExpLiteral;
        }

        void parse() override;

        string to_string() override;

    private:
        string regex;
        string flags;
    };
} }
