#pragma once

#include "AstNode.h"
#include "ArgumentList.h"
#include "../decoders.h"
#include <vector>

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class ArrayExpr : public AstNode {
    public:
        explicit ArrayExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        ArgumentList* argumentList = nullptr;

    };
} }
