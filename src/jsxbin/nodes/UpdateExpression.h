#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class UpdateExpression : public AstNode {
public:
    explicit UpdateExpression(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::UpdateExpression;
    }

    void parse() override;

    string to_string() override;

private:
    AstNode* variable = nullptr;
    int operation = 0;
    bool postfix = false;
};

END_NS(nodes) END_NS(jsxbin)
