#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class DeleteExpr : public AstNode {
    public:
        explicit DeleteExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        string name;
        AstNode *argument = nullptr;
    };
}
