#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class UnaryExpression : public AstNode {
public:
    explicit UnaryExpression(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::UnaryExpression;
    }

    void parse() override;

    string to_string() override;

private:
    string op;
    AstNode* expression = nullptr;
};

END_NS(nodes) END_NS(jsxbin)
