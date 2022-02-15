#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
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
        AstNode* finallyBlock;
        vector<TryCatchLayer> layers;
        int length;
    };
} }
