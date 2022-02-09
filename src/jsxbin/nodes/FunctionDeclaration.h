#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class FunctionDeclaration : public AstNode {
public:
    explicit FunctionDeclaration(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::FunctionDeclaration;
    }

    void parse() override;

    string to_string() override;

private:
    decoders::LineInfo bodyInfo;
    decoders::FunctionSignature signature;
    int _type = 0;
};

END_NS(nodes) END_NS(jsxbin)
