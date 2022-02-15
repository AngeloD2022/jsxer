#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class XMLConstantExpression : public AstNode {
    public:
        explicit XMLConstantExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::XMLConstantExpression;
        }

        void parse() override;

        string to_string() override;

    private:
        map<AstNode*, int> children;
    };
} }
