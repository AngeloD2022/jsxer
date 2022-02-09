#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class XMLAssignmentExpr : public AstNode {
    public:
        explicit XMLAssignmentExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        map<AstNode*, int> children;
    };
} }
