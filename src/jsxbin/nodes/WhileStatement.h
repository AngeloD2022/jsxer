#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class WhileStatement : public AstNode {
public:
    explicit WhileStatement(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::WhileStatement;
    }

    void parse() override;

    string to_string() override;

private:
    decoders::LineInfo bodyInfo;
    AstNode* condition = nullptr;
};

END_NS(nodes) END_NS(jsxbin)
