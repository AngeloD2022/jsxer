#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class ThrowStatement : public AstNode {
    public:
        explicit ThrowStatement(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info lineInfo;
        AstNode *expression;
    };
}
