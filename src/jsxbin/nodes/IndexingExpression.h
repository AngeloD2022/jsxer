#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class IndexingExpression : public AstNode {
public:
    explicit IndexingExpression(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::IndexingExpression;
    }

    void parse() override;

    string to_string() override;

private:
    string arrayName;
    string expression;
};

END_NS(nodes) END_NS(jsxbin)
