#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include "ArgumentList.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class FunctionCallExpr : public AstNode {
    public:
        explicit FunctionCallExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        AstNode *function = nullptr;
        AstNode *args = nullptr;
        bool constructorCall;
    };
}
