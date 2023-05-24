#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include "ListExpression.h"

namespace jsxer::nodes {
    class CallExpression : public AstNode {
    public:
        DEFINE_NODE_TYPE(CallExpression);

        explicit CallExpression(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        AstOpNode function;
        AstOpNode args;
        bool constructorCall{};
    };
}
