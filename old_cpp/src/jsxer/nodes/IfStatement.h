#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class IfStatement : public AstNode {
    public:
        explicit IfStatement(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::IfStatement;
        }

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo bodyInfo;
        AstOpNode test;
        AstOpNode otherwise;
    };
}
