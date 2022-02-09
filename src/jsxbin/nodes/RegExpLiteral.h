#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class RegExpLiteral : public AstNode {
public:
    explicit RegExpLiteral(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::RegExpLiteral;
    }

    void parse() override;

    string to_string() override;

private:
    string regex;
    string flags;
};

END_NS(nodes) END_NS(jsxbin)
