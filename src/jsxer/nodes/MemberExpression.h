#pragma once

#include "AstNode.h"
#include "../decoders.h"

#include <cstdlib>

namespace jsxer::nodes {
    class MemberExpression : public AstNode {
    public:
        DEFINE_NODE_TYPE(MemberExpression);

        explicit MemberExpression(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::Reference memberInfo;
        AstOpNode objInfo;
    };
}
