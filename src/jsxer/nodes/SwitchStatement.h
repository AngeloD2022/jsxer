#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include "ListExpression.h"

namespace jsxer::nodes {
    class SwitchStatement : public AstNode {
    public:
        explicit SwitchStatement(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::SwitchStatement;
        }

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo lineInfo;
        AstOpNode switchValue;
        vector<AstOpNode> cases;
        vector<AstOpNode> implementations;
    };
}
