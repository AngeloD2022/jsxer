#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class XMLConstantExpression : public AstNode {
    public:
        DEFINE_NODE_TYPE(XMLConstantExpression);

        explicit XMLConstantExpression(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        map<AstOpNode, unsigned long> children;
    };
}
