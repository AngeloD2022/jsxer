#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
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
            AstOpNode exceptionFilter;
            AstOpNode catchBlock;
        };

        decoders::LineInfo tryBlock;
        AstOpNode finallyBlock;
        vector<TryCatchLayer> layers;
        size_t length{};
    };
}
