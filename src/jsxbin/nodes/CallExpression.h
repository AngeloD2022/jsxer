#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include "ListExpression.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class CallExpression : public AstNode {
public:
    explicit CallExpression(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::CallExpression;
    }

    void parse() override;

    string to_string() override;

private:
    AstNode* function = nullptr;
    AstNode* args = nullptr;
    bool constructor = false;
};

END_NS(nodes) END_NS(jsxbin)
