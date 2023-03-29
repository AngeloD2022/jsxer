#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include <algorithm>

namespace jsxer::nodes {
    class StatementList : public AstNode {
    public:
        DEFINE_NODE_TYPE(StatementList);

        explicit StatementList(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        size_t length{};
        decoders::LineInfo body;
        vector<AstOpNode> statements;
    };
}
