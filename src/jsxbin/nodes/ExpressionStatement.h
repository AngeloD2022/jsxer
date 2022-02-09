#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class ExpressionStatement : public AstNode {
public:
    explicit ExpressionStatement(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::ExpressionStatement;
    }

    void parse() override;

    string to_string() override;

private:
    decoders::LineInfo lineInfo;
    AstNode* expression = nullptr;
};

END_NS(nodes) END_NS(jsxbin)
