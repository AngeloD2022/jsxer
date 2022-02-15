#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class FunctionExpression : public AstNode {
    public:
        explicit FunctionExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::FunctionExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo lineInfo;
        AstNode* expression = nullptr;
    };
} }
