#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class BreakStatement : public AstNode {
    public:
        DEFINE_NODE_TYPE(BreakStatement);

        explicit BreakStatement(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo labelInfo;
        string jmpLocation;
        bool breakStatement = false;
    };
}
