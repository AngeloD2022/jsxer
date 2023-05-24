#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class IndexingExpression : public AstNode {
    public:
        DEFINE_NODE_TYPE(IndexingExpression);

        explicit IndexingExpression(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        string arrayName;
        string expression;
    };
}
