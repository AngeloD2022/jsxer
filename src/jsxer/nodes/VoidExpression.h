#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class VoidExpression : public AstNode {
    public:
        DEFINE_NODE_TYPE(VoidExpression);

        explicit VoidExpression(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        AstOpNode defaultNamespaceFxnCall;
    };
}
