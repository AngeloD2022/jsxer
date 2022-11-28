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
        shared_ptr<AstNode> switchValue;
        vector<shared_ptr<AstNode>> cases;
        vector<shared_ptr<AstNode>> implementations;
    };
} }
