#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class XMLDescendantsExpression : public AstNode {
    public:
        DEFINE_NODE_TYPE(XMLDescendantsExpression);

        explicit XMLDescendantsExpression(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::Reference descendants;
        AstOpNode object;
    };
}
