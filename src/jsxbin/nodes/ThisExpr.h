#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class ThisExpr : public AstNode {
    public:
        explicit ThisExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::Reference reference;
    };
} }
