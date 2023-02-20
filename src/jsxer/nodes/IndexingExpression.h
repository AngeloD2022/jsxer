#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class IndexingExpression : public AstNode {
    public:
        explicit IndexingExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::IndexingExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        string arrayName;
        string expression;
    };
}
