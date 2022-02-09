#pragma once

#include "AstNode.h"
#include "../decoders.h"

#include <cstdlib>

using namespace jsxbin;

namespace jsxbin::nodes {
    class MemberExpr : public AstNode {
    public:
        explicit MemberExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::reference memberInfo;
        AstNode *objInfo;
    };
}
