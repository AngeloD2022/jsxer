#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class LogicalExpr : public AstNode {
    public:
        explicit LogicalExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        string opName;
        AstNode *leftExpr;
        AstNode *rightExpr;
        string leftLiteral;
        string rightLiteral;
    };
} }
