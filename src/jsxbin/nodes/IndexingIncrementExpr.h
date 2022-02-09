#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class IndexingIncrementExpr : public AstNode {
    public:
        explicit IndexingIncrementExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        AstNode *variable = nullptr;
        int operation = 0;
        bool postfix = false;
    };
} }
