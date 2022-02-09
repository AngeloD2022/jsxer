#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class LocalUpdateExpression : public AstNode {
public:
    explicit LocalUpdateExpression(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::LocalUpdateExpression;
    }

    void parse() override;

    string to_string() override;

private:
    string id;
    int length = 0;
    string operation;
    bool postfix = false;
};

END_NS(nodes) END_NS(jsxbin)
