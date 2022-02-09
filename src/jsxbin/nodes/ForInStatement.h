#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class ForInStatement : public AstNode {
    public:
        explicit ForInStatement(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info bodyInfo;
        AstNode *loopVariable = nullptr;
        AstNode *objExpression = nullptr;
        int length;
        string id;
        bool forEach = false;
    };
}
