#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class XMLQualifiedNameExpression : public AstNode {
public:
    explicit XMLQualifiedNameExpression(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::XMLQualifiedNameExpression;
    }

    void parse() override;

    string to_string() override;

private:
    decoders::Reference descendants;
    AstNode* object = nullptr;
};

END_NS(nodes) END_NS(jsxbin)