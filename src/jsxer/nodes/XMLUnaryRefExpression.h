#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class XMLUnaryRefExpression : public AstNode {
    public:
        explicit XMLUnaryRefExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::XMLUnaryRefExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        string id;
        AstNode *node;
    };
} }
