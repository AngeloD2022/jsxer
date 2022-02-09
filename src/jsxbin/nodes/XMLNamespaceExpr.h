#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class XMLNamespaceExpr : public AstNode {
    public:
        explicit XMLNamespaceExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::Reference namespaceObject;
        AstNode* object = nullptr;
        string xmlId;
    };
} }
