#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class DoWhileStatement : public AstNode {
public:
    explicit DoWhileStatement(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::DoWhileStatement;
    }

    void parse() override;

    string to_string() override;

private:
    decoders::LineInfo body;
    AstNode *condition = nullptr;
};

END_NS(nodes) END_NS(jsxbin)
