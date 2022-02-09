#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class XMLDescendantsExpression : public AstNode {
public:
    explicit XMLDescendantsExpression(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::XMLDescendantsExpression;
    }

    void parse() override;

    string to_string() override;

private:
    decoders::Reference namespaceObject;
    AstNode* object = nullptr;
    string xmlId;
};

END_NS(nodes) END_NS(jsxbin)
