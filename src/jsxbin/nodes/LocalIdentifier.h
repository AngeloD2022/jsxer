#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

// LocalVariable
class LocalIdentifier : public AstNode {
public:
    explicit LocalIdentifier(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::LocalIdentifier;
    }

    void parse() override;

    string to_string() override;

private:
    decoders::Reference reference;
    int _type = 0;
};

END_NS(nodes) END_NS(jsxbin)
