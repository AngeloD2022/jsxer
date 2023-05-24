#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class ForStatement : public AstNode {
    public:
        DEFINE_NODE_TYPE(ForStatement);

        explicit ForStatement(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo bodyInfo;
        AstOpNode initial;
        AstOpNode test;
        AstOpNode update;
    };
}
