#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class Program : AstNode {
    public:
        DEFINE_NODE_TYPE(Program);

        explicit Program(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        AstOpNode body;
    };
}
