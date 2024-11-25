#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class LocalUpdateExpression : public AstNode {
    public:
        explicit LocalUpdateExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::LocalUpdateExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        string id;
        size_t length = 0;
        string operation;
        bool postfix = false;
    };
}
