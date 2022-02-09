#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class TryStatement : public AstNode {
    public:
        explicit TryStatement(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:

        struct tc_layer {
            string arg;
            AstNode *exceptionFilter;
            AstNode *catchBlock;
        };

        decoders::line_info tryBlock;
        AstNode *finallyBlock;
        vector<tc_layer> layers;
        int length;
    };
}
