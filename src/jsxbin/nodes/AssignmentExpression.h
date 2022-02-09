#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include "BinaryExpression.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class AssignmentExpression : public AstNode {
public:
    explicit AssignmentExpression(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::AssignmentExpression;
    }

    void parse() override;

    string to_string() override;

private:
    AstNode* variable = nullptr;
    AstNode* expression = nullptr;
    string literal;
    bool shorthand = false;
};

END_NS(nodes) END_NS(jsxbin)
