#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class JumpStatement : public AstNode {
    public:
        explicit JumpStatement(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo labelInfo;
        string jmpLocation;
        bool breakStatement = false;
    };
} }
