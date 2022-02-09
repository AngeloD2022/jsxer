#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class XMLDoubleDotDescendantsExpr : public AstNode {
    public:
        explicit XMLDoubleDotDescendantsExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::Reference descendants;
        AstNode* object;
    };
} }
