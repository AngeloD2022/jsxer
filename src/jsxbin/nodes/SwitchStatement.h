#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include "ArgumentList.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class SwitchStatement : public AstNode {
    public:
        explicit SwitchStatement(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo lineInfo;
        AstNode* switchValue;
        vector<AstNode*> cases;
        vector<AstNode*> implementations;
    };
} }
