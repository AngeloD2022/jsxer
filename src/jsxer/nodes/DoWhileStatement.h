#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class DoWhileStatement : public AstNode {
    public:
        explicit DoWhileStatement(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::DoWhileStatement;
        }

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo body;
        AstOpNode condition;
    };
}
