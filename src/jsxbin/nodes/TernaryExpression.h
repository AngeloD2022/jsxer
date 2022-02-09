#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class TernaryExpression : public AstNode {
public:
    explicit TernaryExpression(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::TernaryExpression;
    }

    void parse() override;

    string to_string() override;

private:
    AstNode* condition = nullptr;
    AstNode* node_true = nullptr;
    AstNode* node_false = nullptr;
};

END_NS(nodes) END_NS(jsxbin)
