#pragma once

#include "AstNode.h"
#include "ArgumentList.h"
#include "../decoders.h"
#include <vector>

using namespace jsxbin;

namespace jsxbin::nodes {
    class ArrayExpr : public AstNode {
    public:
        explicit ArrayExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        ArgumentList* argumentList = nullptr;

    };
}
