#pragma once

#include "AstNode.h"
#include "../decoders.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

class TryStatement : public AstNode {
public:
    explicit TryStatement(Reader& reader) : AstNode(reader) {}

    NodeType type() override {
        return NodeType::TryStatement;
    }

    void parse() override;

    string to_string() override;

private:
    struct TryCatchLayer {
        string arg;
        AstNode* exceptionFilter;
        AstNode* catchBlock;
    };

    decoders::LineInfo tryBlock;
    AstNode* finallyBlock = nullptr;
    vector<TryCatchLayer> layers;
    int length = 0;
};

END_NS(nodes) END_NS(jsxbin)
