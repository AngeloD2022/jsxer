#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class BreakStatement : public AstNode {
    public:
        explicit BreakStatement(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::BreakStatement;
        }

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo labelInfo;
        string jmpLocation;
        bool breakStatement = false;
    };
}
