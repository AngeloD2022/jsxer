#pragma once

#include "AstNode.h"
#include "../decoders.h"

#include <cstdlib>

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class MemberExpression : public AstNode {
public:
    explicit MemberExpression(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::MemberExpression;
    }

    void parse() override;

    string to_string() override;

private:
    decoders::Reference memberInfo;
    AstNode* objInfo = nullptr;
};

END_NS(nodes) END_NS(jsxbin)
