#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class XMLUnaryRefExpression : public AstNode {
public:
    explicit XMLUnaryRefExpression(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::XMLUnaryRefExpression;
    }

    void parse() override;

    string to_string() override;

private:
    string id;
    AstNode* node = nullptr;
};

END_NS(nodes) END_NS(jsxbin)
