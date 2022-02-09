#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class DoWhileExpr : public AstNode {
    public:
        explicit DoWhileExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info body;
        AstNode *condition = nullptr;
    };
}
