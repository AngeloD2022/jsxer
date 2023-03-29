#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class LogicalExpression : public AstNode {
    public:
        DEFINE_NODE_TYPE(LogicalExpression);

        explicit LogicalExpression(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        string opName;
        AstOpNode leftExpr;
        AstOpNode rightExpr;
        string leftLiteral;
        string rightLiteral;
    };
}
