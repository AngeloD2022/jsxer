#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class SetDefaultXMLNamespaceExpr : public AstNode {
    public:
        explicit SetDefaultXMLNamespaceExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        AstNode *defaultNamespaceFxnCall;
    };
} }
