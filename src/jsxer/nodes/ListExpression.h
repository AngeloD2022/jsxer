#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include <vector>

BEGIN_NS(jsxer) BEGIN_NS(nodes)

class ListExpression : public AstNode {
public:
    explicit ListExpression(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::ListExpression;
    }

    void parse() override;

    void set_for_loop(bool x);

    string to_string() override;

    vector<AstNode*> arguments;

private:
    bool for_loop = false;
    bool sequence_expr = false;
};

END_NS(nodes) END_NS(jsxbin)
