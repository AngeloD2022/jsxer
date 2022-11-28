#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxer;

namespace jsxer { namespace nodes {
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
            shared_ptr<AstNode> exceptionFilter;
            shared_ptr<AstNode> catchBlock;
        };

        decoders::LineInfo tryBlock;
        shared_ptr<AstNode> finallyBlock;
        vector<TryCatchLayer> layers;
        int length;
    };
} }
