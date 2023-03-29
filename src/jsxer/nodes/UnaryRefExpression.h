#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class UnaryRefExpression : public AstNode {
    public:
        DEFINE_NODE_TYPE(UnaryRefExpression);

        explicit UnaryRefExpression(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        string name;
        AstOpNode argument;
    };
}
