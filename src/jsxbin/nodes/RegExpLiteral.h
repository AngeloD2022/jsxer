#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class RegExpLiteral : public AstNode {
    public:
        explicit RegExpLiteral(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        string regex;
        string flags;
    };
}
