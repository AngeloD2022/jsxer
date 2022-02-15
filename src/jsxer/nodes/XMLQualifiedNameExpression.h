#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxer;

namespace jsxer { namespace nodes {
    class XMLQualifiedNameExpression : public AstNode {
    public:
        explicit XMLQualifiedNameExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::XMLQualifiedNameExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        decoders::Reference namespaceObject;
        AstNode* object = nullptr;
        string xmlId;
    };
} }
