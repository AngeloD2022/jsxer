#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include <algorithm>

using namespace jsxbin;

namespace jsxbin::nodes {
    class StatementList : public AstNode {
    public:
        explicit StatementList(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        size_t length;
        decoders::line_info body;
        vector<AstNode*> statements;
    };
}
