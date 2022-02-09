#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class BinaryExpression : public AstNode {
public:
    explicit BinaryExpression(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::BinaryExpression;
    }

    void parse() override;

    string to_string() override;

    string get_op(){
        return this->op;
    }

    string get_op_name() {
        return this->op_name;
    }

private:
    string op_name;
    string op;
    AstNode* left = nullptr;
    AstNode* right = nullptr;
    string literalLeft;
    string literalRight;
    string create_expr(const string &literal, AstNode *exprNode);
};

END_NS(nodes) END_NS(jsxbin)
