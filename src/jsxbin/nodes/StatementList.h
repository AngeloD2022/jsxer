#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class StatementList : public AstNode {
public:
    explicit StatementList(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::StatementList;
    }

    void parse() override;

    string to_string() override;

private:
    size_t length = 0;
    decoders::LineInfo body;
    vector<AstNode*> statements;
};

END_NS(nodes) END_NS(jsxbin)
