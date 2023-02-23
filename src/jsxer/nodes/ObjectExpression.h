#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include <algorithm>

namespace jsxer::nodes {
    class ObjectExpression : public AstNode {
    public:
        explicit ObjectExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::ObjectExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        string objectId;
        map<string, AstOpNode> properties;
    };
}
