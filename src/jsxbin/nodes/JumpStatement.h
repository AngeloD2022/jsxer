#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class JumpStatement : public AstNode {
    public:
        explicit JumpStatement(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info labelInfo;
        string jmpLocation;
        bool breakStatement = false;
    };
}
