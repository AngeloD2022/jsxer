#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class XMLDescendantsExpression : public AstNode {
    public:
        explicit XMLDescendantsExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::XMLDescendantsExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        decoders::Reference descendants;
        AstNode* object;
    };
} }
