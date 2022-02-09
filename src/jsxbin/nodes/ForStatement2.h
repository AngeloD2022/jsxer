#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class ForStatement2 : public AstNode {
    public:
        explicit ForStatement2(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo bodyInfo;
        AstNode *initial = nullptr;
        AstNode *test = nullptr;
        AstNode *update = nullptr;
    };
} }
