#pragma once

#include "AstNode.h"
#include "ListExpression.h"
#include "../decoders.h"
#include <vector>

namespace jsxer::nodes {
    class ArrayExpression : public AstNode {
    public:
        explicit ArrayExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::ArrayExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        OpListExpression argumentList;
    };
}
