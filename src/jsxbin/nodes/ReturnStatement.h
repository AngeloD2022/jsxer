#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class ReturnStatement : public AstNode {
    public:
        explicit ReturnStatement(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info lineInfo;
        AstNode *expression;
    };
}
