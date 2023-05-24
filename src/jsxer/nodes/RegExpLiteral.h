#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class RegExpLiteral : public AstNode {
    public:
        DEFINE_NODE_TYPE(RegExpLiteral);

        explicit RegExpLiteral(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        string regex;
        string flags;
    };
}
