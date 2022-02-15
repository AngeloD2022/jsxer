#pragma once

#include "AstNode.h"
#include "ListExpression.h"
#include "../decoders.h"
#include <vector>

using namespace jsxer;

namespace jsxer { namespace nodes {
    class ArrayExpression : public AstNode {
    public:
        explicit ArrayExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::ArrayExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        ListExpression* argumentList = nullptr;

    };
} }
