#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class ConstAssignment : public AstNode {
public:
    explicit ConstAssignment(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::ConstAssignment;
    }

    void parse() override;

    string to_string() override;

private:
    string name;
    int length = 0;
    AstNode *expression = nullptr;
    string literal;
    bool boolean_1 = false;
    bool boolean_2 = false;
};

END_NS(nodes) END_NS(jsxbin)
