#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class WhileStatement : public AstNode {
    public:
        explicit WhileStatement(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info bodyInfo;
        AstNode *condition;
    };
}
