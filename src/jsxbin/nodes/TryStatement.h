#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class TryStatement : public AstNode {
    public:
        explicit TryStatement(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:

        struct tc_layer {
            string arg;
            AstNode *exceptionFilter;
            AstNode *catchBlock;
        };

        decoders::LineInfo tryBlock;
        AstNode *finallyBlock;
        vector<tc_layer> layers;
        int length;
    };
} }
