#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class EmptyExpression : public AstNode {
public:
    explicit EmptyExpression(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::EmptyExpression;
    }

    void parse() override;

    string to_string() override;

private:
    // nothing
};

END_NS(nodes) END_NS(jsxbin)

