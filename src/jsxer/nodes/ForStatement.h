#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxer;

namespace jsxer { namespace nodes {
    class ForStatement : public AstNode {
    public:
        explicit ForStatement(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::ForStatement;
        }

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo bodyInfo;
        AstNode *initial = nullptr;
        AstNode *test = nullptr;
        AstNode *update = nullptr;
    };
} }
