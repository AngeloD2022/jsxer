#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class WithStatement : public AstNode {
public:
    explicit WithStatement(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::WithStatement;
    }

    void parse() override;

    string to_string() override;

private:
    decoders::LineInfo bodyInfo;
    AstNode* object = nullptr;
};

END_NS(nodes) END_NS(jsxbin)
