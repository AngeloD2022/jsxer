#pragma once

#include "AstNode.h"
#include "../decoders.h"

#include <cstdlib>

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class MemberExpr : public AstNode {
    public:
        explicit MemberExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::Reference memberInfo;
        AstNode* objInfo;
    };
} }
