#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class ConditionalExpr : public AstNode {
    public:
        explicit ConditionalExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        AstNode* condition;
        AstNode* node_true;
        AstNode* node_false;

    };
} }
