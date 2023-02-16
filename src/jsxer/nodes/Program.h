#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class Program : AstNode {
    public:
        explicit Program(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::Program;
        }

        void parse() override;

        string to_string() override;

    private:
        AstOpNode body;
    };
}
