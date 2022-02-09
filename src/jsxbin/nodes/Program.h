#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class Program : AstNode {
    public:
        explicit Program(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        AstNode *child = nullptr;
    };
} }
