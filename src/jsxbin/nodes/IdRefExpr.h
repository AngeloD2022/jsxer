#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class IdRefExpr : public AstNode {
    public:
        explicit IdRefExpr(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::reference reference;
        int type = 0;
    };
}
