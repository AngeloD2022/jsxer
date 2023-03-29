#pragma once

#include "AstNode.h"
#include "BinaryExpression.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class LocalAssignmentExpression : public AstNode {
    public:
        DEFINE_NODE_TYPE(LocalAssignmentExpression);

        explicit LocalAssignmentExpression(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

        void suppress_declarative_keyword(bool value);

    private:
        string var_name;
        string literal;
        AstOpNode expression;
        bool declarative_suppress = false;
        bool shorthand = false;
        bool declaration = false;
    };
}
