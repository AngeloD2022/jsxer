#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class XMLConstantExpression : public AstNode {
public:
    explicit XMLConstantExpression(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::XMLConstantExpression;
    }

    void parse() override;

    string to_string() override;

private:
    map<AstNode*, int> children;
};

END_NS(nodes) END_NS(jsxbin)
