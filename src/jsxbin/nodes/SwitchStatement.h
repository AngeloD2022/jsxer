#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include "ArgumentList.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class SwitchStatement : public AstNode {
    public:
        explicit SwitchStatement(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info lineInfo;
        AstNode *switchValue;
        vector<AstNode*> cases;
        vector<AstNode*> implementations;
    };
}
