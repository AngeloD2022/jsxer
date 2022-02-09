#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class LogicalExpression : public AstNode {
public:
    explicit LogicalExpression(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::LogicalExpression;
    }

    void parse() override;

    string to_string() override;

private:
    string opName;
    AstNode* leftExpr = nullptr;
    AstNode* rightExpr = nullptr;
    string leftLiteral;
    string rightLiteral;
};

END_NS(nodes) END_NS(jsxbin)
