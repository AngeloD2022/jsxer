#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxer;

namespace jsxer { namespace nodes {
    class WithStatement : public AstNode {
    public:
        explicit WithStatement(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::WithStatement;
        }

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo bodyInfo;
        AstNode *object;
    };
} }
