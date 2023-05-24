#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class DebuggerStatement : public AstNode {
    public:
        DEFINE_NODE_TYPE(DebuggerStatement);

        explicit DebuggerStatement(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo lineInfo;
    };
}
