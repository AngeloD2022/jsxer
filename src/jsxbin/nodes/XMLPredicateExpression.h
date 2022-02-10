#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
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
        AstNode *object;
        AstNode *member;
    };
} }
