#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include "ListExpression.h"

using namespace jsxer;

namespace jsxer { namespace nodes {
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
        AstNode* switchValue;
        vector<AstNode*> cases;
        vector<AstNode*> implementations;
    };
} }
