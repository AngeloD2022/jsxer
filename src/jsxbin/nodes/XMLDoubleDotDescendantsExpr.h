#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class XMLDoubleDotDescendantsExpr : public AstNode {
    public:
        explicit XMLDoubleDotDescendantsExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::reference descendants;
        AstNode *object;
    };
}
