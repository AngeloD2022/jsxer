#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include "ArgumentList.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class FunctionCallExpr : public AstNode {
    public:
        explicit FunctionCallExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        AstNode *function = nullptr;
        AstNode *args = nullptr;
        bool constructorCall;
    };
} }
