#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxer;

namespace jsxer { namespace nodes {
    class ThrowStatement : public AstNode {
    public:
        explicit ThrowStatement(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::ThrowStatement;
        }

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo lineInfo;
        shared_ptr<AstNode> expression;
    };
} }
