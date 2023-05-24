#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class Identifier : public AstNode {
    public:
        DEFINE_NODE_TYPE(Identifier);

        explicit Identifier(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        string id;
        bool unknown = false;
    };
}
