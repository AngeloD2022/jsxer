#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxer;

namespace jsxer { namespace nodes {
    class ReturnStatement : public AstNode {
    public:
        explicit ReturnStatement(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::ReturnStatement;
        }

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo lineInfo;
        AstNode* expression;
    };
} }
