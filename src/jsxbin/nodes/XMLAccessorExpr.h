#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class XMLAccessorExpr : public AstNode {
    public:
        explicit XMLAccessorExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::reference reference;
        AstNode *object;
        AstNode *member;
    };
}
