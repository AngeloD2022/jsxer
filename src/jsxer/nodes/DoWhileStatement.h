#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class DoWhileStatement : public AstNode {
    public:
        DEFINE_NODE_TYPE(DoWhileStatement);

        explicit DoWhileStatement(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo body;
        AstOpNode condition;
    };
}
