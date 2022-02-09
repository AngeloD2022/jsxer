#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class ConstantLiteral : public AstNode {
public:
    explicit ConstantLiteral(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::ConstantLiteral;
    }

    void parse() override;

    string to_string() override;

private:
    string value;
};

END_NS(nodes) END_NS(jsxbin)
