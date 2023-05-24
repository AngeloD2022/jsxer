#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class WhileStatement : public AstNode {
    public:
        DEFINE_NODE_TYPE(WhileStatement);

        explicit WhileStatement(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo bodyInfo;
        AstOpNode condition;
    };
}
