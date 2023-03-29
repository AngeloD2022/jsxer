#pragma once

#include "AstNode.h"
#include "ListExpression.h"
#include "../decoders.h"
#include <vector>

namespace jsxer::nodes {
    class ArrayExpression : public AstNode {
    public:
        DEFINE_NODE_TYPE(ArrayExpression);

        explicit ArrayExpression(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        OpListExpression argumentList;
    };
}
