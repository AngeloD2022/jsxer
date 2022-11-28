#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxer;

namespace jsxer { namespace nodes {
    class ExpressionStatement : public AstNode {
    public:
        explicit ExpressionStatement(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::ExpressionStatement;
        }

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo lineInfo;
        shared_ptr<AstNode> expression = nullptr;
    };
} }
