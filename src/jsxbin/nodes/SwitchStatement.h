#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include "ListExpression.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class SwitchStatement : public AstNode {
public:
    explicit SwitchStatement(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::SwitchStatement;
    }

    void parse() override;

    string to_string() override;

private:
    decoders::LineInfo lineInfo;
    AstNode *switchValue = nullptr;
    vector<AstNode*> cases;
    vector<AstNode*> implementations;
};

END_NS(nodes) END_NS(jsxbin)