#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include <algorithm>

namespace jsxer::nodes {
    class ObjectExpression : public AstNode {
    public:
        DEFINE_NODE_TYPE(ObjectExpression);

        explicit ObjectExpression(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        string objectId;
        map<string, AstOpNode> properties;
    };
}
