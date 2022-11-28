#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxer;

namespace jsxer { namespace nodes {
    class IfStatement : public AstNode {
    public:
        explicit IfStatement(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::IfStatement;
        }

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo bodyInfo;
        shared_ptr<AstNode> test = nullptr;
        shared_ptr<AstNode> otherwise = nullptr;
    };
} }
