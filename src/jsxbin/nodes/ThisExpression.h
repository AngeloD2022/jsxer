#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class ThisExpression : public AstNode {
    public:
        explicit ThisExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::ThisExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        decoders::Reference reference;
    };
} }
