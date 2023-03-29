#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class XMLQualifiedNameExpression : public AstNode {
    public:
        DEFINE_NODE_TYPE(XMLQualifiedNameExpression);

        explicit XMLQualifiedNameExpression(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::Reference namespaceObject;
        AstOpNode object;
        string xmlId;
    };
}
