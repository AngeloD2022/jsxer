#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class Identifier : public AstNode {
    public:
        explicit Identifier(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::Identifier;
        }

        void parse() override;

        string to_string() override;

    private:
        string id;
        bool unknown = false;
    };
} }
