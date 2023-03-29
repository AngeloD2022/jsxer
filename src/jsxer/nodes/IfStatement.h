#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class IfStatement : public AstNode {
    public:
        DEFINE_NODE_TYPE(IfStatement);

        explicit IfStatement(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo bodyInfo;
        AstOpNode test;
        AstOpNode otherwise;
    };
}
