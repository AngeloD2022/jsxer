#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class UpdateExpression : public AstNode {
    public:
        explicit UpdateExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::UpdateExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        AstOpNode variable;
        int operation = 0;
        bool postfix = false;
    };
}
