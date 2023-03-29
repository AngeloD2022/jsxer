#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include "BinaryExpression.h"

namespace jsxer::nodes {
    class AssignmentExpression : public AstNode {
    public:
        DEFINE_NODE_TYPE(AssignmentExpression);

        explicit AssignmentExpression(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        AstOpNode variable;
        AstOpNode expression;
        string literal;
        bool shorthand{};
    };
}
