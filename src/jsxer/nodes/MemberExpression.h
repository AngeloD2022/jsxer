#pragma once

#include "AstNode.h"
#include "../decoders.h"

#include <cstdlib>

namespace jsxer::nodes {
    class MemberExpression : public AstNode {
    public:
        explicit MemberExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::MemberExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        decoders::Reference memberInfo;
        AstOpNode objInfo;
    };
}
