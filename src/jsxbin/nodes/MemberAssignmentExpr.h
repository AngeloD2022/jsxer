#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include "BinaryExpr.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class MemberAssignmentExpr : public AstNode {
    public:
        explicit MemberAssignmentExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        AstNode *variable;
        AstNode *expression;
        string literal;
        bool shorthand;
    };
} }
