#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class WhileStatement : public AstNode {
    public:
        explicit WhileStatement(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::WhileStatement;
        }

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo bodyInfo;
        AstOpNode condition;
    };
}
