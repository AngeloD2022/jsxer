#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class XMLNamespaceExpr : public AstNode {
    public:
        explicit XMLNamespaceExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::reference namespaceObject;
        AstNode *object = nullptr;
        string xmlId;
    };
}
