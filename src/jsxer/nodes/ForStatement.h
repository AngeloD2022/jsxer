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
        shared_ptr<AstNode> initial = nullptr;
        shared_ptr<AstNode> test = nullptr;
        shared_ptr<AstNode> update = nullptr;
    };
} }
