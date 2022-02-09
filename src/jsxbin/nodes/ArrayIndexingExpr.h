#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class ArrayIndexingExpr : public AstNode {
    public:
        explicit ArrayIndexingExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        string arrayName;
        string expression;
    };
}
