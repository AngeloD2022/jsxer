#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxer;

namespace jsxer { namespace nodes {
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
        shared_ptr<AstNode> object;
        shared_ptr<AstNode> member;
    };
} }
