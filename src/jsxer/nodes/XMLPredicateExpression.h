#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class XMLPredicateExpression : public AstNode {
    public:
        explicit XMLPredicateExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::XMLPredicateExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        decoders::Reference reference;
        AstOpNode object;
        AstOpNode member;
    };
}
