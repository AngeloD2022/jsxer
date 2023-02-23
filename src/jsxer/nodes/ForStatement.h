#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class ForStatement : public AstNode {
    public:
        explicit ForStatement(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::ForStatement;
        }

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo bodyInfo;
        AstOpNode initial;
        AstOpNode test;
        AstOpNode update;
    };
}
