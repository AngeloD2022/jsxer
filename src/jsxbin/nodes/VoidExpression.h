#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class VoidExpression : public AstNode {
public:
    explicit VoidExpression(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::VoidExpression;
    }

    void parse() override;

    string to_string() override;

private:
    AstNode* expression = nullptr;
};

END_NS(nodes) END_NS(jsxbin)
