#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include <algorithm>

namespace jsxer::nodes {
    class StatementList : public AstNode {
    public:
        explicit StatementList(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::StatementList;
        }

        void parse() override;

        string to_string() override;

    private:
        size_t length{};
        decoders::LineInfo body;
        vector<AstOpNode> statements;
    };
}
