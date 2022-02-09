#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class DoWhileExpr : public AstNode {
    public:
        explicit DoWhileExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo body;
        AstNode *condition = nullptr;
    };
} }
