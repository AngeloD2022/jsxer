#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class IncrementExpr : public AstNode {
    public:
        explicit IncrementExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        string id;
        int length = 0;
        string operation;
        bool postfix = false;
    };
}
