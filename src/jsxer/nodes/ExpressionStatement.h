#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class ExpressionStatement : public AstNode {
    public:
        DEFINE_NODE_TYPE(ExpressionStatement);

        explicit ExpressionStatement(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo lineInfo;
        AstOpNode expression;
    };
}
