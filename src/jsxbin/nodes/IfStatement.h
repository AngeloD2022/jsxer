#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class IfStatement : public AstNode {
    public:
        explicit IfStatement(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo bodyInfo;
        AstNode *test = nullptr;
        AstNode *otherwise = nullptr;
    };
} }
