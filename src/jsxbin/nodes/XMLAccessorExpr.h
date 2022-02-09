#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class XMLAccessorExpr : public AstNode {
    public:
        explicit XMLAccessorExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::Reference reference;
        AstNode *object;
        AstNode *member;
    };
} }
