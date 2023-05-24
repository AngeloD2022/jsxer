#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class LocalUpdateExpression : public AstNode {
    public:
        DEFINE_NODE_TYPE(LocalUpdateExpression);

        explicit LocalUpdateExpression(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        string id;
        size_t length = 0;
        string operation;
        bool postfix = false;
    };
}
