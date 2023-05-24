#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class XMLPredicateExpression : public AstNode {
    public:
        DEFINE_NODE_TYPE(XMLPredicateExpression);

        explicit XMLPredicateExpression(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::Reference reference;
        AstOpNode object;
        AstOpNode member;
    };
}
