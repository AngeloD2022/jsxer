#pragma once

#include "AstNode.h"
#include "BinaryExpression.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class LocalAssignmentExpression : public AstNode {
public:
    explicit LocalAssignmentExpression(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::LocalAssignmentExpression;
    }

    void parse() override;

    string to_string() override;

private:
    string var_name;
    string literal;
    AstNode *expression = nullptr;
    bool shorthand = false;
    bool declaration = false;
};

END_NS(nodes) END_NS(jsxbin)
