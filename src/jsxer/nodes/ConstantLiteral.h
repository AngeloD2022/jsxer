#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class ConstantLiteral : public AstNode {
    public:
        DEFINE_NODE_TYPE(ConstantLiteral);

        explicit ConstantLiteral(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        string value;
    };
}
