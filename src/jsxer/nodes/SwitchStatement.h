#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include "ListExpression.h"

namespace jsxer::nodes {
    class SwitchStatement : public AstNode {
    public:
        DEFINE_NODE_TYPE(SwitchStatement);

        explicit SwitchStatement(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo lineInfo;
        AstOpNode switchValue;
        vector<AstOpNode> cases;
        vector<AstOpNode> implementations;
    };
}
