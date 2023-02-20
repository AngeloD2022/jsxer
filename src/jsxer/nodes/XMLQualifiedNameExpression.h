#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
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
        AstOpNode object;
        string xmlId;
    };
}
