#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class ForStatement2 : public AstNode {
    public:
        explicit ForStatement2(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info bodyInfo;
        AstNode *initial = nullptr;
        AstNode *test = nullptr;
        AstNode *update = nullptr;
    };
}
