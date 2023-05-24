#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class ThisExpression : public AstNode {
    public:
        DEFINE_NODE_TYPE(ThisExpression);

        explicit ThisExpression(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::Reference reference;
    };
}
