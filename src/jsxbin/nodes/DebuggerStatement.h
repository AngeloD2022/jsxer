#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class DebuggerStatement : public AstNode {
public:
    explicit DebuggerStatement(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::DebuggerStatement;
    }

    void parse() override;

    string to_string() override;

private:
    decoders::LineInfo lineInfo;
};

END_NS(nodes) END_NS(jsxbin)
