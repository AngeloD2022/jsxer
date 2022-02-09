#pragma once

#include "AstNode.h"
#include "BinaryExpr.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class AssignmentExpr : public AstNode {
    public:

        explicit AssignmentExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        string var_name;
        string literal;
        AstNode *expression = nullptr;
        bool shorthand = false;
        bool declaration = false;
    };
}
