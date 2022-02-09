#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class SetDefaultXMLNamespaceExpr : public AstNode {
    public:
        explicit SetDefaultXMLNamespaceExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        AstNode *defaultNamespaceFxnCall;
    };
}
