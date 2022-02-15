#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class Program : AstNode {
    public:
        explicit Program(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::Program;
        }

        void parse() override;

        string to_string() override;

    private:
        AstNode *body = nullptr;
    };
} }
