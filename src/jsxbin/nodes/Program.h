#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class Program : AstNode {
public:
    explicit Program(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::Program;
    }

    void parse() override;

    string to_string() override;

private:
    AstNode* body = nullptr;
};

END_NS(nodes) END_NS(jsxbin)
