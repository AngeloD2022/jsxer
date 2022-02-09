#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include <algorithm>

using namespace jsxbin;

namespace jsxbin::nodes {
    class ObjectExpr : public AstNode {
    public:
        explicit ObjectExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        string objectId;
        map<string, AstNode*> properties;
    };
}
