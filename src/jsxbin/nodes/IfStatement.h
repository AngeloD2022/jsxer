#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class IfStatement : public AstNode {
public:
    explicit IfStatement(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::IfStatement;
    }

    void parse() override;

    string to_string() override;

private:
    decoders::LineInfo bodyInfo;
    AstNode* test = nullptr;
    AstNode* otherwise = nullptr;
};

END_NS(nodes) END_NS(jsxbin)
