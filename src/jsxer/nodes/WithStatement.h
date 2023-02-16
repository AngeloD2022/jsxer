#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class WithStatement : public AstNode {
    public:
        explicit WithStatement(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::WithStatement;
        }

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo bodyInfo;
        AstOpNode object;
    };
}
