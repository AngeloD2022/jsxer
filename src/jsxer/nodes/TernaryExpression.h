#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class TernaryExpression : public AstNode {
    public:
        DEFINE_NODE_TYPE(TernaryExpression);

        explicit TernaryExpression(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        AstOpNode condition;
        AstOpNode node_true;
        AstOpNode node_false;
    };
}
