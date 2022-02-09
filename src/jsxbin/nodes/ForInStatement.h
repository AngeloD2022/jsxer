#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class ForInStatement : public AstNode {
public:
    explicit ForInStatement(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::ForInStatement;
    }

    void parse() override;

    string to_string() override;

private:
    decoders::LineInfo bodyInfo;
    AstNode* loopVariable = nullptr;
    AstNode* objExpression = nullptr;
    int length = 0;
    string id;
    bool forEach = false;
};

END_NS(nodes) END_NS(jsxbin)
