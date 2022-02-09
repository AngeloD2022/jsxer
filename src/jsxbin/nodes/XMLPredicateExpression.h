#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

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
    AstNode* object = nullptr;
    AstNode* member = nullptr;
};

END_NS(nodes) END_NS(jsxbin)
