#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class ThrowStatement : public AstNode {
    public:
        explicit ThrowStatement(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::ThrowStatement;
        }

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo lineInfo;
        AstOpNode expression;
    };
}
