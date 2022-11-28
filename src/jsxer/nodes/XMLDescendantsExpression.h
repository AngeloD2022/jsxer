#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxer;

namespace jsxer { namespace nodes {
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
        shared_ptr<AstNode> object;
    };
} }
