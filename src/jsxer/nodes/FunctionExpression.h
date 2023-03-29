#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class FunctionExpression : public AstNode {
    public:
        DEFINE_NODE_TYPE(FunctionExpression);

        explicit FunctionExpression(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo lineInfo;
        AstOpNode expression;
    };
}
