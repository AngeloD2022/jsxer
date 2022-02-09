#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class IfStatement : public AstNode {
    public:
        explicit IfStatement(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info bodyInfo;
        AstNode *test = nullptr;
        AstNode *otherwise = nullptr;
    };
}
